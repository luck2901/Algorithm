#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;
#define endl "\n"

int N, M, x, y, K, upDice, downDice;

int maps[21][21];
int dice[6] = { 1,5,4,0,2,3 };
int dice_num[6];
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };

void change_direction(int d) {
    int tmp = dice[0];
    switch (d) {
    case 1:
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
        break;
    case 2 :
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[2];
        dice[2] = tmp;
        break;
    case 3 :
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
        break;
    case 4 : 
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d; cin >> N >> M >> y >> x >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maps[i][j];

    for (int i = 0; i < K; i++) {
        int cmd; cin >> cmd;
        y += dy[cmd];
        x += dx[cmd];
        if (y < 0 || x < 0 || y >= N || x >= M) {
            y -= dy[cmd];
            x -= dx[cmd];           
            continue;
        }
        change_direction(cmd);
        if (maps[y][x] == 0) {
            maps[y][x] = dice_num[dice[5]];
        }
        else {
            dice_num[dice[5]] = maps[y][x];
            maps[y][x] = 0;
        }
        cout << dice_num[dice[0]] << endl;
    }
}