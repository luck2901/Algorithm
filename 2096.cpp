#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;
#define endl "\n"

int max_dp[2][3];
int min_dp[2][3];
int arr[100001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    for (int i = 0; i < 3; i++)
        max_dp[0][i] = min_dp[0][i] = arr[0][i];

    int i = 0, j = 0;
    for (int k = 1; k < N; k++) {
        if (k % 2 == 0) {
            i = 0;
            j = 1;
        }
        else {
            i = 1;
            j = 0;
        }
        max_dp[i][0] = max(max_dp[j][0], max_dp[j][1]) + arr[k][0];
        max_dp[i][1] = max(max(max_dp[j][0], max_dp[j][1]), max_dp[j][2]) + arr[k][1];
        max_dp[i][2] = max(max_dp[j][1], max_dp[j][2]) + arr[k][2];
        min_dp[i][0] = min(min_dp[j][0], min_dp[j][1]) + arr[k][0];
        min_dp[i][1] = min(min(min_dp[j][0], min_dp[j][1]), min_dp[j][2]) + arr[k][1];
        min_dp[i][2] = min(min_dp[j][1], min_dp[j][2]) + arr[k][2];
    }

    cout << max(max(max_dp[i][0], max_dp[i][1]), max_dp[i][2]) << " " << min(min(min_dp[i][0], min_dp[i][1]), min_dp[i][2])<< endl;
}
