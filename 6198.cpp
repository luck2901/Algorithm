#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>

using namespace std;

#define endl "\n"

long long int cnt[80001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> input;
    stack<pair<int, int> > s;

    cin >> N;

    for (int i = 0; i < N;i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }

    long long int answer = 0;

    for (int i = N - 1; i >= 0;i--)
    {
        while (!s.empty() && s.top().first < input[i])
        {
            answer += (cnt[s.top().second] + 1);
            cnt[i] += cnt[s.top().second]+1;
            s.pop();
        }
        s.push(make_pair(input[i], i));
    }

    cout << answer << endl;
}