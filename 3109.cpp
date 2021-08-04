#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int R, C;
char bread[10001][501];
bool check[10001][501];
int dy[3] = {-1, 0, 1};
int dx[3] = {1, 1, 1};
vector<pair<int, int> > v;
int answer = 0;

bool DFS(int y, int x)
{
    if (x == C - 1)
    {
        answer++;
        return true;
    }
    for (int i = 0; i < 3;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= R || nx >= C || ny < 0 || nx < 0 || bread[ny][nx]=='x' || check[ny][nx])
            continue;
        check[ny][nx] = true;
        if(DFS(ny, nx))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R;  i++)
        for (int j = 0; j < C; j++)
            cin >> bread[i][j];

    for (int i = 0; i < R;i++)
    {
        DFS(i, 0);
    }
    cout << answer << endl;
}

// 5 9
// .x.....x.
// .x..x..x.
// .x..x..x.
// ....x....
// .x..x..x.