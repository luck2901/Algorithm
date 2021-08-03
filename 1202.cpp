#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<pair<int, int> > info;
priority_queue<int> q;
vector<int> bag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;
        info.push_back(make_pair(m, v));
    }

    for (int i = 0; i < K;i++)
    {
        int c;
        cin >> c;
        bag.push_back(c);
    }

    sort(info.begin(), info.end());
    sort(bag.begin(), bag.end());
    int idx = 0;
    long long sum = 0;

    for (int i = 0; i < K;i++)
    {
        int bagSize = bag[i];

        while(idx < N)
        {
            if(bagSize >= info[idx].first)
            {
                q.push(info[idx].second);
                idx++;
            }
            else
                break;
        }
        if (!q.empty())
        {
            sum += q.top();
            q.pop();
        }
    }
    cout << sum << endl;
}