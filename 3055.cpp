#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int R, C, wy, wx, t = 0;
char map[51][51];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
vector<pair<int, int>>water;
vector<pair<int, int>>m;

void bfs() {
    queue<pair<int, int>>move;
    queue<pair<int, int>>q;
    int cnt = 1;
    while (!m.empty()) {
        for (auto i : water) q.push({ i.first,i.second });
        water.clear();
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (map[ny][nx] == '.') {
                    map[ny][nx] = '*';
                    water.push_back({ ny,nx });
                }
                else if (map[ny][nx] == 'S') {
                    map[ny][nx] = '*';
                    water.push_back({ ny,nx });
                }
            }
        }
        for (auto i : m) move.push({ i.first,i.second });
        m.clear();
        int movesize = move.size();
        for (int i = 0; i < movesize; i++) {
            int y = move.front().first;
            int x = move.front().second;
            move.pop();
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (map[ny][nx] == '.') {
                    map[ny][nx] = 'S';
                    m.push_back({ ny,nx });
                }
                else if (map[ny][nx] == 'D')
                {
                    cout << t + 1 << endl;
                    return;
                }
            }
        }
        t++;
    }
    cout << "KAKTUS" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == '*') water.push_back({ i,j });
            else if (map[i][j] == 'S') m.push_back({ i,j });
        }

    bfs();

}