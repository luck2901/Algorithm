#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

char maps[1001][1001];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int jy, jx, fy, fx;

void bfs()
{
    queue<pair<int, int> > Jihoon;
    vector<pair<int, int> > nextJ;
    vector<pair<int, int> > nextF;
    queue<pair<int, int>> Fire;
    Jihoon.push(make_pair(jy, jx));
    Fire.push(make_pair(fy, fx));
    while(!q.empty())
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;

    cin >> R >> C;

    for (int i = 0; i < R;i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C;j++)
        {
            maps[i][j] = s[j];
            if(s[i]=='J'){
                jy = i;
                jx = j;
            }else if(s[i]=='F'){
                fy = i;
                fx = j;
            }
        }
    }
}