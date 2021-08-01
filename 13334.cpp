#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<pair<int,int> > container;
priority_queue<int> q;

bool compare(pair<int,int> a, pair<int,int>b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, answer = 0;

    cin >> n;

    for (int i = 0; i < n;i++)
    {
        int start, end;
        cin >> start >> end;

        if(start < end)
            container.push_back(make_pair(start, end));
        else
            container.push_back(make_pair(end, start));
    }

    cin >> d;

    sort(container.begin(), container.end(), compare);

    for (int i = 0; i < container.size();i++)
    {
        int start = container[i].first;
        int end = container[i].second;
        
        if(end - start > d)
            continue;

        q.push(-start);

        while(!q.empty())
        {
            if(-q.top() < end - d)
                q.pop();
            else {
                answer = max(answer, (int)q.size());
                break;
            }
        }
    }
    cout << answer << endl;
}