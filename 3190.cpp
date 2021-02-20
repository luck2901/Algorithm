#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>

using namespace std;

deque<pair<int,int>>snake;
vector<pair<int, char>>cmd;
int check[101][101];
int apple[101][101];
//ºÏ µ¿ ³² ¼­
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, L; cin >> N >> K;
    snake.push_back({ 0, 0 });
    for (int i = 0; i < K; i++)
    {
        int y, x; cin >> y >> x;
        apple[y-1][x-1] = 1;
    }
    cin >> L;
    int pretime = 0;
    int tag = 1;
    int y = 0, x = 0;
    check[0][0] = 1;
    for (int i = 0; i < L; i++)
    {
        int t;
        char c; cin >> t >> c;
        cmd.push_back({ t,c });
    }
    int i = 0;
    for (i = 0;; i++)
    {
        y += dy[tag];
        x += dx[tag];
        if (y < 0 || x < 0 || y >= N || x >= N || check[y][x]) break;
        if (!apple[y][x]) {
            check[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        check[y][x] = 1;
        snake.push_front({ y, x });
        if (cmd[i].second == 'D') tag = tag + 3 & 3;
        else if (cmd[i].second == 'L') tag = tag + 1 & 3;
    }
    cout << i - 1 << endl;
}