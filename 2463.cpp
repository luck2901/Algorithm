#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>
#include <set>

using namespace std;

#define endl "\n"

int h, w;
char maps[111][111];
bool check[26];
bool visit[111][111];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int cnt = 0;

void BFS()
{
    queue<pair<int, int> > q;
    queue<pair<int, int> > alp[26];
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny > h + 1 || nx > w + 1)
                continue;
            if (visit[ny][nx] || maps[ny][nx] == '*')
                continue;

            if ('A' <= maps[ny][nx] && maps[ny][nx] <= 'Z')
            {
                if (!check[maps[ny][nx] - 'A'])
                    alp[maps[ny][nx] - 'A'].push(make_pair(ny, nx));
                else
                {
                    q.push(make_pair(ny, nx));
                    visit[ny][nx] = true;
                }
            }
            else if ('a' <= maps[ny][nx] && maps[ny][nx] <= 'z')
            {

                if (!check[maps[ny][nx] - 'a'])
                {
                    while (!alp[maps[ny][nx] - 'a'].empty())
                    {
                        q.push(alp[maps[ny][nx] - 'a'].front());
                        alp[maps[ny][nx]-'a'].pop();
                    }
                    check[maps[ny][nx] - 'a'] = true;
                }
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
            else
            {
                if (maps[ny][nx] == '$')
                    cnt++;
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
                }
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

    for (int t = 0; t < tc; t++)
    {
        cin >> h >> w;

        memset(check, 0, sizeof(check));
        memset(visit, 0, sizeof(visit));
        memset(maps, 0, sizeof(maps));
        cnt = 0;

        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> maps[i][j];

        string key;
        cin >> key;
        for (int i = 0; i < key.length(); i++)
        {
            if (key[i] == '0')
                continue;
            check[key[i] - 'a'] = true;
        }

        BFS();
        cout << cnt << endl;
    }
}