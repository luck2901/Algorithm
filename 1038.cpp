#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

long long dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    queue<long long> q;

    for (int i = 1; i <= 9;i++)
    {
        q.push(i);
        dp[i] = i;
    }
    if(N>=0 && N<=10)
    {
        cout << N << endl;
        return 0;
    }
    int index = 10;
    while(index <= N && !q.empty())
    {
        long long tmp = q.front();
        long long Dtmp = tmp % 10;
        q.pop();
        for (int i = 0; i < Dtmp; i++)
        {
            long long ttmp = tmp * 10 + i;
            q.push(ttmp);
            dp[index++] = ttmp;
        }
    }

    if(dp[N]!=0 && index >= N)
        cout << dp[N] << endl;
    else
        cout << -1 << endl;
}