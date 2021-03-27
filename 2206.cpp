#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, M;
int map[1001][1001];
int cnt[1001][1001][2];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int bfs()
{
    queue<pair<pair<int, int>,int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    cnt[0][0][0] = 1;
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool tag = q.front().second;
        q.pop();
        if(y == N - 1 && x == M - 1)
            return cnt[y][x][tag];
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (map[ny][nx] == 1 && tag == false)
            {
                q.push(make_pair(make_pair(ny, nx), true));
                cnt[ny][nx][1] = cnt[y][x][tag] + 1;
            }
            if (map[ny][nx] == 0 && !cnt[ny][nx][tag])
            {
                q.push(make_pair(make_pair(ny, nx), tag));
                cnt[ny][nx][tag] = cnt[y][x][tag] + 1;
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

    cin >> N >> M;

    for (int i = 0; i < N;i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    int result = bfs();

    cout << result << endl;

}