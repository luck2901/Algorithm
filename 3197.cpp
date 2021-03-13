#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int R, C, idx = 0, cnt = 0;
char map[1501][1501];
queue<pair<int, int> > water;
queue<pair<int, int> > water_ice;
queue<pair<int, int> > swan;
queue<pair<int, int> > swan_ice;
int swanIndex[2][2];
bool visit[1501][1501];
bool tag = false;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void waterMove()
{
    while (!water.empty())
    {
        int y = water.front().first;
        int x = water.front().second;
        water.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue;
            if (map[ny][nx] == 'X')
            {
                map[ny][nx] = '.';
                water_ice.push(make_pair(ny, nx));
            }
        }
    }
}
void swanMove()
{
    while (!swan.empty() && !tag)
    {
        int y = swan.front().first;
        int x = swan.front().second;
        swan.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || visit[ny][nx])
                continue;
            if (map[ny][nx] == '.')
            {
                swan.push(make_pair(ny, nx));
                visit[ny][nx] = 1;
            }
            else if (map[ny][nx] == 'L')
            {
                tag = 1;
                visit[ny][nx] = 1;
                break;
            }
            else if (map[ny][nx] == 'X')
            {
                swan_ice.push(make_pair(ny, nx));
                visit[ny][nx] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 'X')
                water.push(make_pair(i, j));
            if (map[i][j] == 'L')
            {
                swanIndex[idx][0] = i;
                swanIndex[idx][1] = j;
                idx++;
            }
        }
    swan.push(make_pair(swanIndex[0][0], swanIndex[0][1]));
    visit[swanIndex[0][0]][swanIndex[0][1]] = 1;
    int Day = 0;
    while (!tag)
    {
        swanMove();
        if (tag)
            break;
        waterMove();
        swan = swan_ice;
        water = water_ice;
        while (!swan_ice.empty())
            swan_ice.pop();
        while (!water_ice.empty())
            water_ice.pop();
        Day++;
    }
    cout << Day << endl;
}