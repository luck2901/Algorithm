#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<pair<int, int> > oil;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, P;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        int a, b;
        cin >> a >> b;
        oil.push_back(make_pair(a, b));
    }
    cin >> L >> P;
    sort(oil.begin(), oil.end());

    priority_queue < int> q;
    bool tag = true;
    int start = 0, remainOil = P, result = 0 ;
    while (remainOil < L)
    {
        while(start < N && oil[start].first <= remainOil){
            q.push(oil[start++].second);
        }
        if(q.empty()){
            result = -1;
            break;
        }
        remainOil += q.top();
        q.pop();
        result++;
    }
    cout << result << endl;
}