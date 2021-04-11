#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

bool tag = true;
char field[12][6];
bool check[12][6];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int y, int x)
{
    int cnt = 1;
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    q.push(make_pair(y, x));
    v.push_back(make_pair(y, x));
    check[y][x] = 1;
    while(!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 12 || nx >= 6 || ny < 0 || nx < 0 || check[ny][nx])
                continue;
            if(field[y][x]==field[ny][nx])
            {
                q.push(make_pair(ny, nx));
                v.push_back(make_pair(ny, nx));
                check[ny][nx] = 1;
                cnt++;
            }
        }
    }
    if (cnt >= 4)
    {
        for (auto i : v)
        {
            field[i.first][i.second] = '.';
        }
        tag = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 12; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++)
        {
            field[i][j] = s[j];
        }
    }
    int result = 0;
    while (tag)
    {
        tag = false;
        memset(check, 0, sizeof(check));
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (field[i][j] != '.' && !check[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        if (tag == false)
            break;
        result++;
        for (int i = 11; i >= 1; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if(field[i][j]=='.')
                {
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if(field[k][j]!='.')
                        {
                            field[i][j] = field[k][j];
                            field[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
}