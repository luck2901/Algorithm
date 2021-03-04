#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int N, M;
int robot[51][51];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int y, x, d; cin >> y >> x >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> robot[i][j];

    int result = 1;
    robot[y][x] = 2;
    int nx, ny, nd;
    while (true) {
        int tag = 0;
        int td = d;
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            nd = ((d + 3) % 4);
            ny = y + dy[nd];
            nx = x + dx[nd];
            if (robot[ny][nx] == 0) {
                tag = 1;
                break;
            }
            else if (robot[ny][nx] == 1 || robot[ny][nx] == 2 || (nx < 0 || ny < 0 || ny >= N || nx >= M)){
                d = nd;
                cnt++;
            }
        }
        if (tag == 1) {
            result++;
            robot[ny][nx] = 2;
            d = nd;
        }
        if (cnt == 4) {
            ny = y - dy[td];
            nx = x - dx[td];
            d = td;
            if (robot[ny][nx] == 1 || (nx < 0 || ny < 0 || ny >= N || nx >= M)) break;
        }
        y = ny;
        x = nx;
    }
    cout << result << endl;
}