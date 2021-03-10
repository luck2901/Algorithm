#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
int arr[16][16];
int dp[16][16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    int start = 1, checky = 0, checkx = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = start;
            start++;
            if (arr[i][j] == K)
            {
                checky = i;
                checkx = j;
            }
        }
    if (K == 0) {
        checky = N - 1;
        checkx = M - 1;
    }

    for (int i = 0; i <= checky; i++)
        for (int j = 0; j <= checkx; j++)
        {
            if (i == 0 && j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = dp[i][j - 1];
            else if (j == 0) dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    int result1 = dp[checky][checkx];

    if (K == 0) {
        cout << result1 << endl;
        return 0;
    }

    for (int i = checky; i < N; i++)
        for (int j = checkx; j < M; j++)
        {
            if (i == checky && j == checkx) dp[i][j] = 1;
            else if (i == checky) dp[i][j] = dp[i][j - 1];
            else if (j == checkx) dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    int result2 = dp[N - 1][M - 1];

    cout << result1 * result2 << endl;
}