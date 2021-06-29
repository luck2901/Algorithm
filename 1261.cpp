#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, M;
int maze[101][101];
int broke[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs()
{
    queue<pair<int, int> >q;
    memset(broke, 10001, sizeof(broke));
    q.push(make_pair(0, 0));
    broke[0][0] = 0;

    while(!q.empty()) 
    {
        int y = q.front().first;
        int x = q.front().second;
        int aoj = broke[y][x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= M || ny < 0 || nx < 0)
                continue;
            if(maze[ny][nx]==0 && broke[ny][nx] > broke[y][x])
            {
                broke[ny][nx] = broke[y][x];
                q.push(make_pair(ny, nx));
            }
            else if(maze[ny][nx]==1 && broke[y][x]+1 < broke[ny][nx])
            {
                broke[ny][nx] = broke[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = s[j] - '0';
        }
    }

    bfs();

    cout << broke[N-1][M-1] << endl;
}