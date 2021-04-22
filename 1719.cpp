#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

#define endl "\n"

vector<pair<int,int> > v[201];
int path[201];
string ans[201][201];
int n, m;

void bfs(int node)
{
    vector<int> dist(n + 1, 987654321);
    priority_queue<pair<int, int> > q;
    q.push(make_pair(node, 0));
    dist[node] = 0;
    while(!q.empty())
    {
        int cur = q.top().first;
        int cost = -q.top().second;
        q.pop();
        if(cost > dist[cur])
            continue;
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                q.push(make_pair(next, -dist[next]));
                path[next] = cur;
            }
        }
    }
    for (int i = 1; i <= n;i++)
    {
        if(node == i)
            ans[node][i] = "-";
        else{
            int t = i;
            while (path[t] != node)
            {
                t = path[t];
            }
            ans[node][i] = to_string(t);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m;i++)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        v[a].push_back(make_pair(b,dis));
        v[b].push_back(make_pair(a, dis));
    }

    for (int i = 1; i <= n;i++)
    {
        bfs(i);
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}