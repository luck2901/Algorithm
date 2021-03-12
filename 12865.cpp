#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int weight[110];
int value[110];
int dp[110][100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K] << endl;
}