#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, M;
int parent[201];
vector<int> v;

int find(int u)
{
    if(parent[u]==u)
        return u;
    else
        return parent[u] = find(parent[u]);
}
void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            if(num==1)
                Union(i, j);
        }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int tmp = v[0];
    for (int i = 1; i < M; i++)
    {
        tmp = find(tmp);
        int tmp2 = find(v[i]);
        if (tmp != tmp2)
        {
            cout << "NO" << endl;
            return 0;
        }
        tmp = v[i];
    }
    cout << "YES" << endl;
}