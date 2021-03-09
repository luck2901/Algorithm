#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;
#define endl "\n"

int N, M, T, t;
bool gram = false;
int map[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
bool check[101][101];
bool check2[101][101];
queue<pair<pair<int, int>, bool>>q;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    q.push({ { 0,0 }, 0 });
    check[0][0] = 1;
    bool princess = false;
    for (int i = 0; i <= T; i++) {
        int qsize = q.size();
        for (int j = 0; j < qsize; j++) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            bool gram = q.front().second;
            q.pop();

            if (map[y][x] == 2) {
                gram = true;
            }
            if (y == N - 1 && x == M - 1)
            {
                princess = true;
                break;
            }
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (gram && check2[ny][nx]) continue;
                if (!gram && check[ny][nx]) continue;
                if (!gram && map[ny][nx] == 1) continue;
                if (gram) check2[ny][nx] = true;
                else check[ny][nx] = false;
                q.push({ {ny,nx},gram });
            }
        }
        if (princess) {
            cout << i << endl;
            break;
        }
    }
    if (!princess) {
        cout << "Fail" << endl;
    }
}