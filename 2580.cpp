#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int sudoku[10][10];
vector<pair<int,int> > v;
bool wCheck[10][10];
bool lCheck[10][10];
bool sCheck[10][10];

void dfs(int vIdx)
{
    int y = v[vIdx].first;
    int x = v[vIdx].second;

    if(vIdx == v.size())
    {
        for (int i = 1; i <= 9;i++)
        {
            for (int j = 1; j <= 9;j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (wCheck[y][i] == true || lCheck[x][i] == true || sCheck[((y - 1) / 3) * 3 + ((x - 1) / 3 + 1)][i] == true)
            continue;
        wCheck[y][i] = true;
        lCheck[x][i] = true;
        sCheck[((y - 1) / 3 ) * 3 + ((x - 1) / 3 + 1)][i] = true;
        sudoku[y][x] = i;
        dfs(vIdx + 1);
        wCheck[y][i] = false;
        lCheck[x][i] = false;
        sCheck[((y - 1) / 3) * 3 + ((x - 1) / 3 + 1)][i] = false;
        sudoku[y][x] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 9;i++)
        for (int j = 1; j <= 9;j++)
        {
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0)
                v.push_back(make_pair(i, j));
            else {
                wCheck[i][sudoku[i][j]] = true;
                lCheck[j][sudoku[i][j]] = true;
                sCheck[((i - 1) / 3) * 3 + ((j - 1) / 3 + 1)][sudoku[i][j]] = true;
            }
        }

    dfs(0);
}