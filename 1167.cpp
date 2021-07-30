
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<pair<int, int> > tree[100001];
int dist[100001];
bool check[100001];

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    check[start] = true;
    int maxNum = 0;
    while (!q.empty())
    {
        int curV = q.front();
        q.pop();
        for (int i = 0; i < tree[curV].size(); i++)
        {
            int nextV = tree[curV][i].first;
            int nextC = tree[curV][i].second;
            if (nextC + dist[curV] > dist[nextV] && !check[nextV])
            {
                dist[nextV] = nextC + dist[curV];
                q.push(nextV);
                check[nextV] = true;
                maxNum = dist[nextV];
            }
        }
    }
    return maxNum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v;
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int start;
        cin >> start;
        while (true)
        {
            int ver, dis;
            cin >> ver;
            if (ver == -1)
                break;
            cin >> dis;
            tree[start].push_back(make_pair(ver, dis));
        }
    }

    bfs(1);

    int answer = dist[1];
    int start = 1;

    for (int i = 2; i <= v;i++)
    {
        if(answer < dist[i])
        {
            answer = dist[i];
            start = i;
        }
    }

    memset(check, 0, sizeof(check));
    memset(dist, 0, sizeof(dist));

    bfs(start);

    answer = dist[1];
    start = 1;

    for (int i = 2; i <= v; i++)
    {
        if (answer < dist[i])
        {
            answer = dist[i];
            start = i;
        }
    }

    cout << answer << endl;
}