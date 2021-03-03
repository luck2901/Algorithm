#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sol[2001];
int dp[2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sol[i];
        dp[i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (sol[i] < sol[j])
                dp[i] = max(dp[i], dp[j] + 1);
            result = max(dp[i], result);
        }
    }
    if (N == 1) cout << 0 << endl;
    else
        cout << N - result << endl;
}