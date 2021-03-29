#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"
#define MAX 200001
#define INF 987654321

int V, E, start;
vector<pair<int, int> > v[MAX];
int check[MAX];

void bfs()
{
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, start));
    check[start] = 0;
    while(!q.empty())
    {
        int cost = -q.top().first;
        int current = q.top().second;
        q.pop();
        for (int i = 0; i < v[current].size();i++)
        {
            int next = v[current][i].first;
            int nCost = v[current][i].second;
            if(check[next] > cost + nCost)
            {
                check[next] = cost + nCost;
                q.push(make_pair(-check[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if(check[i]==INF)
            cout << "INF" << endl;
        else
            cout << check[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> start;

    for (int i = 0; i < E; i++)
    {
        int start, end, c;
        cin >> start >> end >> c;
        v[start].push_back(make_pair(end, c));
    }
    for (int i = 1; i <= V;i++)
        check[i] = INF;

    bfs();
}