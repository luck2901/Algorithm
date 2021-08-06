#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"
#define ll long long

vector<pair<int, pair<int, int> > > v;
int parent[1001];
vector<pair<ll, ll> > adj[1001];
bool check[1001];
ll answer2 = 0;

int find(int a)
{
    if(a==parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
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
    if(a!=b)
        parent[a] = b;
}

void dfs(int x, ll sum)
{
    answer2 = max(sum, answer2);
    check[x] = true;

    for (int i = 0; i < adj[x].size(); i++)
    {
        int nx = adj[x][i].first;
        int cost = adj[x][i].second;
        if(!check[nx])
            dfs(nx, sum + cost);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 0; i < K; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        v.push_back(make_pair(c, make_pair(s, e)));
    }
    sort(v.begin(), v.end());

    ll answer1 = 0;
    for (int i = 0; i < K; i++)
    {
        if(!isSameParent(v[i].second.first, v[i].second.second))
        {
            Union(v[i].second.first, v[i].second.second);
            answer1 += v[i].first;
            adj[v[i].second.first].push_back(make_pair(v[i].second.second, v[i].first));
            adj[v[i].second.second].push_back(make_pair(v[i].second.first, v[i].first));
        }
    }
    cout << answer1 << endl;

    for (int i = 0; i < N;i++)
    {
        dfs(i, 0);
        memset(check, 0, sizeof(check));
    }

    cout << answer2 << endl;
}