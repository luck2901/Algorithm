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
int jy, jx;
int R, C;
vector<pair<int, int> > nextF;
vector<pair<int, int> > nextJ;
int cnt[1001][1001];

int bfs()
{
    queue<pair<int, int> > Jihoon;
    queue<pair<int, int> > Fire;
    nextJ.push_back(make_pair(jy, jx));
    while(nextJ.size())
    {
        for (int i = 0; i < nextJ.size();i++)
        {
            if(maps[nextJ[i].first][nextJ[i].second]!='F')
                Jihoon.push(make_pair(nextJ[i].first, nextJ[i].second));
        }
        for (int i = 0; i < nextF.size();i++)
            Fire.push(make_pair(nextF[i].first, nextF[i].second));
        nextJ.clear();
        nextF.clear();
        while(!Jihoon.empty())
        {
            int y = Jihoon.front().first;
            int x = Jihoon.front().second;
            Jihoon.pop();
            for (int i = 0; i < 4;i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                    return cnt[y][x]+1;
                if(maps[ny][nx]=='.')
                {
                    nextJ.push_back(make_pair(ny, nx));
                    cnt[ny][nx] = cnt[y][x] + 1;
                    maps[ny][nx] = 'J';
                }
            }
        }
        while (!Fire.empty())
        {
            int y = Fire.front().first;
            int x = Fire.front().second;
            Fire.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                    continue;
                if (maps[ny][nx] == '.' || maps[ny][nx]=='J')
                {
                    nextF.push_back(make_pair(ny, nx));
                    maps[ny][nx] = 'F';
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R;i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C;j++)
        {
            maps[i][j] = s[j];
            if(s[j]=='J'){
                jy = i;
                jx = j;
            }
            else if (s[j] == 'F')
            {
                nextF.push_back(make_pair(i, j));
            }
        }
    }

    int answer = bfs();

    if(answer==0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << answer << endl;
}