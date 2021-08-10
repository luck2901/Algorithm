#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, M;
int change;
int before[31][31];
int after[31][31];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
bool check[31][31];
vector<pair<int, int>> v;

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    v.push_back(make_pair(y, x));
    check[y][x] = true;
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || check[ny][nx])
                continue;
            if (before[ny][nx] == before[y][x])
            {
                check[ny][nx] = true;
                v.push_back(make_pair(ny, nx));
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

    int y = -1, x = -1;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> before[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> after[i][j];
            if (after[i][j] != before[i][j])
            {
                y = i;
                x = j;
                change = after[i][j];
            }
        }
    }

    if (y == -1 && x == -1)
    {
        cout << "YES" << endl;
        return 0;
    }

    bfs(y, x);

    for (int i = 0; i < v.size(); i++)
    {
        before[v[i].first][v[i].second] = change;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (before[i][j] != after[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}