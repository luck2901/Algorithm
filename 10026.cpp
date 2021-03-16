#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N;
char map[101][101];
bool check[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j)
{
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    check[i][j] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || check[ny][nx])
                continue;
            if (map[y][x] == map[ny][nx])
            {
                q.push(make_pair(ny, nx));
                check[ny][nx] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (check[i][j])
                continue;
            bfs(i, j);
            cnt++;
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'R')
                map[i][j] = 'G';
        }
    int cnt2 = 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (check[i][j])
                continue;
            bfs(i, j);
            cnt2++;
        }
    cout << cnt << " " << cnt2 << endl;
}