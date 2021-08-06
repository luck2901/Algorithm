#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector < pair<int, pair<int, int> > > v;
int parent[10001];

int find(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node] = find(parent[node]);
}

bool isSameParent(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a==b)
        return true;
    else
        return false;
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a!= b)
        parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, answer = 0;

    cin >> V >> E;
    for (int i = 0; i < E;i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v.push_back(make_pair(cost, make_pair(start, end)));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int i = 0; i < E;i++)
    {
        if(!isSameParent(v[i].second.first, v[i].second.second))
        {
            Union(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }
    cout << answer << endl;
}