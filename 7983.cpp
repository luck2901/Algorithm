#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<pair<int,int> > v;

bool compare(pair<int,int> a, pair<int,int> b)
{

    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int day, finish;
        cin >> day >> finish;
        v.push_back(make_pair(day, finish));
    }

    sort(v.begin(), v.end(), compare);

    int stand = v[0].second - v[0].first;
    for (int i = 1; i < N; i++)
    {
        if(v[i].second < stand)
        {
            stand = v[i].second - v[i].first;
        }
        else{
            stand = stand - v[i].first;
        }
    }
    cout << stand << endl;
}