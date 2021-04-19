#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, result = 0;
int home[17][17];
int dy[] = {0, 1, 1};
int dx[] = {1, 1, 0};

bool possible(int y, int x, int dir)
{
    if(dir==0)
    {
        for (int i = 0; i < 1;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N || home[ny][nx]==1)
                return false;
        }
    }
    else if(dir==1)
    {
        for (int i = 0; i < 3;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N | home[ny][nx] == 1)
                return false;
        }
    }
    else if(dir == 2)
    {
        for (int i = 2; i < 3; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > N | home[ny][nx] == 1)
                return false;
        }
    }
    return true;
}

void dfs(int y, int x, int dir)
{
    if(y == N && x == N)
    {
        result++;
        return;
    }
    if (dir == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(possible(y,x,i))
                dfs(ny, nx, i);
        }
    }
    else if (dir == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (possible(y, x, i))
                dfs(ny, nx, i);
        }
    }
    else if (dir == 2)
    {
        for (int i = 1; i < 3; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (possible(y, x, i))
                dfs(ny, nx, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N;i++)
        for (int j = 1; j <= N;j++)
            cin >> home[i][j];

    dfs(1, 2, 0);

    cout << result << endl;
}