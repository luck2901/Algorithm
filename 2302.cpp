#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int dp[41];
vector<int> vip;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, result = 1;
    cin >> N >> M;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    vip.push_back(0);
    for (int i = 1; i <= M; i++)
    {
        int num;
        cin >> num;
        vip.push_back(num);
    }
    for (int j = 1; j <= M; j++)
    {
        result *= dp[vip[j] - vip[j-1] - 1];
    }
    result *= dp[N - vip[M]];

    cout << result << endl;
}