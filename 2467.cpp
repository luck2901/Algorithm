#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> v;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int start = 0, end = N - 1, result = 2000000000;
    int resultx, resulty;
    while (start < end)
    {
        int sum = v[start] + v[end];
        if (abs(sum) < abs(result))
        {
            result = sum;
            resultx = v[start];
            resulty = v[end];
        }
        if(sum > 0)
            end -= 1;
        else if(sum < 0)
            start += 1;
        else if(sum == 0)
            break;
    }
    cout << resultx << " " << resulty << endl;
}