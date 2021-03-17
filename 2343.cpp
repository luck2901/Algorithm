#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
int v[100001];

bool check(int mid)
{
    int cnt = 1, sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > mid)
            return false;
        sum += v[i];
        if (sum > mid)
        {
            cnt++;
            sum = v[i];
        }
    }
    if (cnt > M)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int start = 1, end = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        end += v[i];
    }
    int result = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (check(mid))
        {
            end = mid - 1;
            result = mid;
        }
        else
            start = mid + 1;
    }
    cout << result << endl;
}