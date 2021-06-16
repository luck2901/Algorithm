#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> vertex[51];
int dist[51];
int answer = 0;

void bfs(int N, int K)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 1));
    dist[1] = 0;

    while (!q.empty())
    {
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();

        for (int i = 0; i < vertex[cur].size(); i++)
        {
            int next = vertex[cur][i].first;
            int ncost = vertex[cur][i].second;
            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                q.push(make_pair(-dist[next], next));
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }
}

int solution(int N, vector<vector<int>> road, int K)
{

    for (int i = 0; i < road.size(); i++)
    {
        vertex[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        vertex[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    for (int i = 1; i <= N; i++)
        dist[i] = 987654321;

    bfs(N, K);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}