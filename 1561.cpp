#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define ll long long
#define endl "\n"

int timeArr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, maxNum = 0;
    cin >> N >> M;

    for (int i = 0; i < M;i++)
    {
        cin >> timeArr[i];
    }

    if(M >= N)
    {
        cout << N << endl;
        return 0;
    }

    ll start = 0;
    ll end = 60000000000;
    ll answerTime, answerCnt;

    while(start <= end)
    {
        ll mid = start + (end-start)/ 2;

        ll sum = M;

        for (int i = 0; i < M;i++)
            sum += (mid / timeArr[i]);

        if(sum >= N)
        {
            answerTime = mid;
            answerCnt = sum;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    
    for (int i = M - 1; i >= 0; i--)
    {
        if (answerTime % timeArr[i] != 0)
            continue;

        if (answerCnt == N)
        {
            cout << i + 1 << endl;
            break;
        }
        answerCnt--;
    }
}