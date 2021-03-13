#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N, M, A, B, C, maxnum = 0, Fac1 = 0, Fac2 = 0;
vector<pair<int, int> > v[10001];
bool check[10001];

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        v[A].push_back(make_pair(B, C));
        v[B].push_back(make_pair(A, C));
        maxnum = max(C, maxnum);
    }
    cin >> Fac1 >> Fac2;
}

bool bfs(int mid)
{
    memset(check, 0, sizeof(check));
    queue<int> q;
    q.push(Fac1);
    check[Fac1] = true;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (n == Fac2)
            return true;
        for (int i = 0; i < v[n].size(); i++)
        {
            int nf = v[n][i].first;
            int nc = v[n][i].second;
            if (check[nf] == false && nc >= mid)
            {
                check[nf] = true;
                q.push(nf);
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    int start = 0;
    int end = maxnum;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (bfs(mid) == true)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end << endl;
}