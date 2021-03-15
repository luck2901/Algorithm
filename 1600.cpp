#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int K, W, H;
int map[201][201];
bool check[201][201][31];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int kdy[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int kdx[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int bfs()
{
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    check[0][0][0] = 1;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int knight = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if (y == H - 1 && x == W - 1)
            return cnt;
        if (knight < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = y + kdy[i];
                int nx = x + kdx[i];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                    continue;
                if (map[ny][nx] == 0 && !check[ny][nx][knight + 1])
                {
                    q.push(make_pair(make_pair(ny, nx), make_pair(knight + 1, cnt + 1)));
                    check[ny][nx][knight + 1] = 1;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                continue;
            if (map[ny][nx] == 0 && !check[ny][nx][knight])
            {
                q.push(make_pair(make_pair(ny, nx), make_pair(knight, cnt + 1)));
                check[ny][nx][knight] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> map[i][j];

    cout << bfs() << endl;
}