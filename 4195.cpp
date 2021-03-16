#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string.h>

using namespace std;

int parent[200001];
int cnt[200001];

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

int uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 1;
    }
    return cnt[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, F;

    cin >> tc;

    while (tc--)
    {
        cin >> F;
        for (int i = 1; i <= F * 2; i++)
        {
            cnt[i] = 1;
            parent[i] = i;
        }
        map<string, int> m;
        string s1, s2;
        int idx = 1, tmp1, tmp2;
        for (int i = 1; i <= F; i++)
        {
            cin >> s1 >> s2;
            if (m[s1] == 0)
                m[s1] = idx++;
            if (m[s2] == 0)
                m[s2] = idx++;
            tmp1 = m[s1];
            tmp2 = m[s2];
            cout << uni(tmp1, tmp2) << "\n";
        }
    }
}