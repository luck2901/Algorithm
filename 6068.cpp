#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

bool compare(pair<int, int> a, pair<int, int>b)
{
    if(a.second==b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<pair<int,int> > v;

    for (int i = 0; i < N;i++)
    {
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }

    sort(v.begin(), v.end(), compare);

    int num = v[0].second - v[0].first;
    for (int i = 1; i < v.size(); i++)
    {
        if(num > v[i].second)
            num = v[i].second - v[i].first;
        else
            num -= v[i].first;
    }
    if(num < 0)
        cout << -1 << endl;
    else
        cout << num << endl;
}