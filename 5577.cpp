#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>

using namespace std;

#define ll long long
#define endl "\n"

int ball[10001];
int answer = 0;

int start(int N, int i)
{
    int left = i;
    int right = i;
    int cnt = 0, ans = 0;
    int now;
    while (left >= 0 && right < N && ball[left] == ball[right])
    {
        now = ball[left];
        cnt = 0;
        if(left==right)
            cnt = -1;
        while (left >= 0 && ball[left] == now)
        {
            left--;
            cnt++;
        }
        while (right < N && ball[right] == now)
        {
            right++;
            cnt++;
        }
        if(cnt >= 4)
        {
            ans += cnt;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> ball[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 3;j++)
        {
            int origin = ball[i];
            ball[i] = j;
            answer = max(answer, start(N, i));
            ball[i] = origin;
        }
    }
    cout << N - answer << endl;
}