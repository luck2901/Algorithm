#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int n, m, s, e;
int answer = 0;
int in_degree[10001];
int mCost[10001];
bool check[10001];
vector<pair<int, int> > r[10001];
vector<pair<int, int> > v[10001];

void topology(int S)
{
    queue<pair<int, int> > q;
    q.push(make_pair(S, 0));
    
    while(!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            mCost[next] = max(mCost[next], nCost+cost);
            in_degree[next]--;

            if(in_degree[next]==0)
                q.push(make_pair(next, mCost[next]));
        }
    }
}

void findPath(int E)
{
    queue<int> q;
    q.push(E);
    check[E] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < r[cur].size();i++)
        {
            int next = r[cur][i].first;
            int cost = r[cur][i].second;
            if (mCost[cur] - cost == mCost[next])
            {
                answer++;
                if (!check[next])
                {
                    check[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back(make_pair(end, cost));
        r[end].push_back(make_pair(start, cost));
        in_degree[end]++;
    }
    cin >> s >> e;

    topology(s);

    cout << mCost[e] << endl;

    findPath(e);

    cout << answer << endl;
}