#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string.h>

using namespace std;

int castle[51][51];
int check[51][51];
int numbering[51][51];
//¼­ µ¿ ºÏ ³²
int dy[17][4] = { {0,0,-1,1}, {0,0,-1,1},{0,0,0,1},{0,0,0,1},{0,0,-1,1},{0,0,-1,1},{0,0,0,1},{0,0,0,1},{0,0,-1,0},{0,0,-1,0},{0,0,0,0},{0,0,0,0},{0,0,-1,0},{0,0,-1,0},{0,0,0,0}, {0,0,0,0} };
int dx[17][4] = { {-1,1,0,0}, {0,1,0,0},{-1,1,0,0},{0,1,0,0},{-1,0,0,0},{0,0,0,0},{-1,0,0,0},{0,0,0,0},{-1,1,0,0},{0,1,0,0},{-1,1,0,0},{0,1,0,0},{-1,0,0,0},{0,0,0,0},{-1,0,0,0}, {0,0,0,0} };
int dy4[4] = { 0,0,-1,1 };
int dx4[4] = { -1,1,0,0 };
int n, m;
int fcnt = 0, scnt = 0, tcnt = 0;
int max_width = 0;
int idx = 0;
vector<int>v;

void bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    check[y][x] = true;
    numbering[y][x] = idx;
    fcnt++;
    scnt = 1;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[castle[y][x]][i];
            int nx = x + dx[castle[y][x]][i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (check[ny][nx] != 0) continue;
            check[ny][nx] = true;
            scnt++;
            numbering[ny][nx] = idx;
            q.push({ ny, nx });
        }
    }
    v.push_back(scnt);
}

int maxarea = 0;
void test(int y, int x) {
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy4[i];
        int nx = x + dx4[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (numbering[ny][nx] != numbering[y][x])
        {
            int sum = v[numbering[ny][nx]] + v[numbering[y][x]];
            maxarea = max(sum, maxarea);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> castle[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (check[i][j]) continue;
            bfs(i, j);
            idx++;
            max_width = max(max_width, scnt);
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            test(i, j);

    cout << fcnt << endl << max_width << endl << maxarea << endl;
}