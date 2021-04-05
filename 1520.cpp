#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int M, N;
int mount[501][501];
int cnt[501][501];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int bfs(int y, int x)
{
    if(y == M-1 && x == N-1)
        return 1;
    if(cnt[y][x] != -1)
        return cnt[y][x];
    cnt[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nexty = y + dy[i];
        int nextx = x + dx[i];
        if (nexty < 0 || nextx < 0 || nexty >= M || nextx >= N)
            continue;
        if (mount[nexty][nextx] < mount[y][x])
        {
            cnt[y][x] += bfs(nexty, nextx);
        }
    }
    return cnt[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> mount[i][j];
            cnt[i][j] = -1;
        }

    int result = bfs(0,0);

    cout << result << endl;
}