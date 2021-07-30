#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"
vector<pair<int, int> > v[1001];
int dist[1001];
int back[1001];
int N, M, X;

void bfs(int start)
{
    priority_queue<pair<int, int> > q;
    dist[start] = 0;
    q.push(make_pair(0, start));
    while(!q.empty())
    {
        int curX = q.top().second;
        int curC = -q.top().first;
        q.pop();
        for (int i = 0; i < v[curX].size();i++)
        {
            int nextX = v[curX][i].first;
            int nextC = v[curX][i].second;
            if (dist[nextX] > curC + nextC)
            {
                dist[nextX] = curC+ nextC;
                q.push(make_pair(-dist[nextX], nextX));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;

    for (int i = 0; i < M;i++)
    {
        int start, end, distance;
        cin >> start >> end >> distance;
        v[start].push_back(make_pair(end, distance));
    }

    int answer = 0;

    for (int j = 0; j <= N; j++)
        dist[j] = 1000001;

    bfs(X);

    for (int j = 0; j <= N;j++)
    {
        back[j] = dist[j];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= N;j++)
            dist[j] = 1000001;
        if (i == X)
            continue;
        bfs(i);
        answer = max(answer, dist[X]+back[i]);
    }

    cout << answer << endl;
}