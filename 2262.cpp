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
    cin >> N;
    vector<int> v(N+2, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int result = 0;
    for (int i = N; i > 1; i--)
    {
        int j;
        for (j = 0; j < N; j++)
        {
            if (v[j] == i)
                break;
        }

        result += v[j] - max(v[j - 1], v[j + 1]);
        for (; j < N ; j++)
            v[j] = v[j + 1];
    }

    cout << result << endl;
}