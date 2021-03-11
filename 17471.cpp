#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N, result = 987654321;
int connection[11][11];
int population[11];
int check[11];
int visit[11];
int caculate()
{
    int a = 0, b = 0;
    for (int i = 1; i <= N; i++)
    {
        if (check[i])
        {
            a += population[i];
        }
        else
        {
            b += population[i];
        }
    }
    return abs(a - b);
}
int bfs(vector<int> v, bool T)
{
    queue<int> q;
    memset(visit, 0, sizeof(visit));
    visit[v[0]] = 1;
    q.push(v[0]);
    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (check[i] == T && visit[i] == false && connection[x][i] == 1)
            {
                visit[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    if (v.size() == cnt)
        return true;
    else
        return false;
}
bool test()
{
    vector<int> a, b;
    for (int i = 1; i <= N; i++)
    {
        if (check[i])
        {
            a.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    if (a.size() == 0 || b.size() == 0)
        return false;
    if (bfs(a, true) == false)
        return false;
    if (bfs(b, false) == false)
        return false;
    return true;
}

void dfs(int cnt, int idx)
{
    if (cnt >= 1)
    {
        if (test())
        {
            int tmp = caculate();
            result = min(result, tmp);
        }
    }
    for (int i = idx; i <= N; i++)
    {
        if (check[i])
            continue;
        check[i] = 1;
        dfs(cnt + 1, i);
        check[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> population[i];

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int connect;
            cin >> connect;
            connection[i][connect] = 1;
            connection[connect][i] = 1;
        }
    }
    dfs(0, 0);

    if (result == 987654321)
        cout << -1 << endl;
    else
        cout << result << endl;
}