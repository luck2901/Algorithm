#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int R, C;
char maps[21][21];
bool check[26];
int answer = 0;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x, int cnt)
{
    answer = max(answer, cnt);

    for (int i = 0; i < 4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || nx < 0 || ny >= R|| nx >= C || check[maps[ny][nx]-'A'] == true)
            continue;
        check[maps[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        check[maps[ny][nx] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> R >> C;

    for (int i = 0; i < R;i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < C; j++)
            maps[i][j] = in[j];
    }

    check[maps[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer << endl;
}