#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int goal;
bool visit[10000];

string bfs(int num)
{
    queue<pair<int, string> > q;
    q.push(make_pair(num, ""));
    visit[num] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        string cur_c = q.front().second;
        q.pop();

        if(x == goal)
            return cur_c;

        int nx = x * 2 % 10000;
        if(!visit[nx])
        {
            visit[nx] = true;
            q.push(make_pair(nx, cur_c + "D"));
        }

        nx = x - 1;
        if(nx < 0 )
            nx = 9999;
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(make_pair(nx, cur_c + "S"));
        }

        nx = (x % 1000) * 10 + (x / 1000);
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(make_pair(nx, cur_c + "L"));
        }

        nx = (x / 10) + (x % 10) * 1000;
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(make_pair(nx, cur_c + "R"));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int start;
        cin >> start >> goal;
        cout << bfs(start) << endl;
        memset(visit, 0, sizeof(visit));
    }
}