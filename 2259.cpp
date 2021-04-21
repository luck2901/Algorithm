#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string.h>

using namespace std;

#define endl "\n"
typedef long long ll;

bool compare(ll a, ll b)
{
    return a >= b;
}

int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    for (int i = 0; i < n;i++)
    {
        int stand = arr[i];
        int x, y, z;
        for (int j = i + 1; j < n;j++)
        {
            x = arr[j];
            for (int k = j; k < n;k++)
            {
                y = arr[k];

                if(x+y>stand)
                    continue;
                for (int t = k; t < n;t++)
                {
                    z = arr[t];
                    if(x+y+z ==stand)
                    {
                        cout << stand << endl;
                        return 0;
                    }
                }
            }
        }
    }
}