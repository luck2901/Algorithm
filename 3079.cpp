#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, M;

vector<int> v;

bool condition(long long mid)
{
    long long result = 0;
    for (int i = 0; i < N; i++)
        result += (mid / v[i]);
    if (result >= M)
        return false;
    else if (result < M)
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    long long maxval =0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        maxval = max(maxval, (long long)v[i]);
    }

    long long start = 0;
    long long end = maxval * M;
    long long result = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (condition(mid))
        {
            start = mid + 1;
        }
        else
        {
            result = mid;
            end = mid - 1;
        }
    }
    cout << result << endl;
}