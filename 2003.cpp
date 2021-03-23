#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int arr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start = 0, end = 0, sum = 0, result = 0, N = 0, M = 0;

    cin >> N >> M;

    for (int i = 0; i < N;i++)
        cin >> arr[i];

    while(true)
    {
        if(sum >=M)
            sum -= arr[start++];
        else if(end == N)
            break;
        else
            sum += arr[end++];
        if(sum == M)
            result++;
    }
    cout << result << endl;
}