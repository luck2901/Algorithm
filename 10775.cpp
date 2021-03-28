#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int parent[100001];

int find(int u)
{
    if(parent[u]==u)
        return u;
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

    int G, P, result = 0;

    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    while(P--)
    {
        int num;
        cin >> num;
        if(find(num)==0)
            break;
        else
        {
            result++;
            Union(find(num), find(num)- 1);
        }
    }
    cout << result << endl;
}