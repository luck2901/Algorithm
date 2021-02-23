#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int N, M, result = 0;
int lab[9][9];
int check[9][9];
vector<pair<int, int>>v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void bfs() {
    queue<pair<int, int>>q;
    for (int i = 0; i < v.size(); i++)
        q.push({ v[i].first,v[i].second });
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (lab[ny][nx] == 0 && !check[ny][nx])
            {
                check[ny][nx] = 1;
                q.push({ ny,nx });
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!lab[i][j] && !check[i][j])
                cnt++;
    result = max(result, cnt);
}

void make_wall(int cnt_wall) {
    if (cnt_wall == 3)
    {
        int sum = 0;
        memset(check, 0, sizeof(check));
        bfs();
        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (!lab[i][j])
            {
                lab[i][j] = 1;
                make_wall(cnt_wall + 1);
                lab[i][j] = 0;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2) v.push_back({ i,j });
        }

    make_wall(0);

    cout << result << endl;
}