#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[201];
bool check[201];
int answer = 0;

void bfs(int num)
{
    queue<int> q;
    q.push(num);
    check[num] = 1;
    answer++;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (check[v[cur][i]])
                continue;
            check[v[cur][i]] = 1;
            q.push(v[cur][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (computers[i][j])
                v[i].push_back(j);
        }
    }
    for (int i = 0; i < computers.size(); i++)
    {
        if (check[i])
            continue;
        bfs(i);
    }

    return answer;
}