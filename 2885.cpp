#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    dp[1] = 1;
    dp[2] = 1;
    int j = 4, idx = 2;
    for (int i = 3; i <= K; i++)
    {
        if (i == j && i != K)
        {
            dp[i] = 0;
            j *= 2;
            idx += 1;
        }
        else if (i % 2 == 1)
        {
            dp[i] = idx;
        }
        else
        {
            dp[i] = dp[i / 2];
        }
    }
    cout << j << " " << dp[K] << endl;
}