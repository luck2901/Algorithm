#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <queue>

using namespace std;

int N, M, chicken_num = 0, answer = 987654321;
int map[51][51];
int check[14];
vector<pair<int, int> > home;
vector<pair<int, int> > chicken;
vector<pair<int, int> > mod;

int findDis()
{
    int result = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int num = 987654321;
        for (int j = 0; j < mod.size(); j++)
        {
            num = min(abs(home[i].first - mod[j].first) + abs(home[i].second - mod[j].second), num);
        }
        result += num;
    }
    return result;
}

void go(int cnt, int idx)
{
    if (cnt == M)
    {
        answer = min(findDis(), answer);
        return;
    }
    for (int i = idx; i < chicken.size(); i++)
    {
        if (check[i] == 1)
            continue;
        check[i] = 1;
        mod.push_back(chicken[i]);
        go(cnt + 1, i);
        check[i] = 0;
        mod.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                chicken.push_back(make_pair(i, j));
            else if (map[i][j] == 1)
                home.push_back(make_pair(i, j));
        }

    go(0, 0);

    cout << answer << endl;
}