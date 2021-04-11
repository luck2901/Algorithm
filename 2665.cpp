#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int n;
int map[51][51];
int check[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    check[0][0] = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= n || nx >= n || ny < 0 || nx < 0)
                continue;
            if(map[ny][nx]==1)
            {
                if(check[ny][nx] > check[y][x])
                {
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = check[y][x];
                }
            }
            else{
                if(check[ny][nx] > check[y][x] + 1)
                {
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = check[y][x] + 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = s[j] - '0';
            check[i][j] = 251;
        }
    }
    bfs();

    cout << check[n - 1][n - 1] << endl;
}