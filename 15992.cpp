#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    vector<pair<int,int> > v;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    int start = v[0].first, end = v[0].second;
    for (int i = 1; i < N; i++)
    {
        if (v[i].second <= end)
            continue;
        else if (v[i].first < end && v[i].second > end)
            end = v[i].second;
        else
        {
            result += (end - start);
            start = v[i].first;
            end = v[i].second;
        }
    }
    cout << result+(end - start) << endl;
}