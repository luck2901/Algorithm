#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int w, h, sang = 0;
char building[1001][1001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
vector<pair<int, int>>f;
bool visited[1001][1001];

int bfs(int y, int x) {
    queue<pair<int, int>>q;
    queue<pair<int, int>>fire;
    q.push({ y,x });
    int t = 0;
    for (int i = 0; i < f.size(); i++) fire.push({ f[i].first, f[i].second });
    while (!q.empty()) {
        int fs = fire.size();
        for (int i = 0; i < fs; i++) {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 > ny || 0 > nx || ny >= h || nx >= w) continue;
                if (building[ny][nx] == '.') {
                    building[ny][nx] = '*';
                    fire.push({ ny,nx });
                }
            }
        }
        int ps = q.size();
        for (int i = 0; i < ps; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (y == 0 || x == 0 || y == h - 1 || x == w - 1) return t + 1;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (0 > ny || 0 > nx || ny >= h || nx >= w) continue;
                if (!visited[ny][nx] && building[ny][nx] != '*' && building[ny][nx] != '#')
                {
                    visited[ny][nx] = true;
                    q.push({ ny,nx });
                }
            }
        }
        t++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        cin >> w >> h;
        int y, x;
        f.clear();
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> building[i][j];
                if (building[i][j] == '@') {
                    y = i;
                    x = j;
                }
                else if (building[i][j] == '*') {
                    f.push_back({ i,j });
                }
            }
        int temp = bfs(y, x);
        if (temp == -1) cout << "IMPOSSIBLE" << endl;
        else cout << temp << endl;

    }
}