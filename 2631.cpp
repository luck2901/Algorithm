#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, result = 0;
vector<int> v;
int dp[201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N;i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if(v[i] > v[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        result = max(result, dp[i]);
    }
    for (int i = 0; i < N;i++)
        cout << dp[i]<<" ";
    cout << N - result << endl;
}