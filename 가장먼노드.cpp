#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[20001];
bool check[20001];
int cost[20001];

void bfs()
{
    queue<int> q;
    q.push(1);
    check[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        int curcost = cost[q.front()];
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (check[v[cur][i]])
                continue;
            check[v[cur][i]] = true;
            cost[v[cur][i]] = curcost + 1;
            q.push(v[cur][i]);
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    for (int i = 0; i < edge.size(); i++)
    {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }

    bfs();

    int maxnum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (maxnum == cost[i])
            answer++;
        else if (maxnum < cost[i])
        {
            answer = 1;
            maxnum = cost[i];
        }
    }

    return answer;
}