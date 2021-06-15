#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int check[101][101];
int cnt[101][101];

int bfs(vector<vector<int>> maps)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = 1;
    memset(cnt, 10001, sizeof(cnt));
    cnt[0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == maps.size() - 1 && x == maps[0].size() - 1)
            return cnt[maps.size() - 1][maps[0].size() - 1];
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= maps.size() || nx >= maps[0].size() || ny < 0 || nx < 0)
                continue;
            if (!check[ny][nx] && maps[ny][nx] == 1)
            {
                q.push({ny, nx});
                check[ny][nx] = 1;
                cnt[ny][nx] = min(cnt[ny][nx], cnt[y][x] + 1);
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    answer = bfs(maps);

    return answer;
}