#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int> > q;
vector<pair<int, int> > v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        v.push_back(make_pair(num1, num2));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int num1 = v[i].first;
        int num2 = v[i].second;
        if (q.empty() || q.top() > num1)
            q.push(num2);
        else if (q.top() <= num1)
        {
            q.pop();
            q.push(num2);
        }
    }
    cout << q.size() << endl;
}