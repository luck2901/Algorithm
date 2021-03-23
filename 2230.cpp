#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int start = 0, end = 0, result = 2000000001, tmp = 0;

    for (int i = 0; i < N;i++)
        cin >> arr[i];

    sort(arr, arr + N);

    while(start < N)
    {
        if(arr[end]-arr[start] >= M)
            result = min(result, arr[end] - arr[start++]);
        else if(arr[end]-arr[start]<M)
            end++;
        else
            {
                cout << M << endl;
                return 0;
            }
    }
    cout << result << endl;
}