#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, result = 0;
    vector<int> v;
    cin >> H >> W;

    for (int i = 0; i < W; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 1; i < W - 1; i++)
    {
        int maxNum1 = -1, maxNum2 = -1;
        for (int j = 0; j < i; j++)
            maxNum1 = max(maxNum1, v[j]);
        for (int j = i + 1; j < W; j++)
            maxNum2 = max(maxNum2, v[j]);
        result += max(0, min(maxNum1, maxNum2) - v[i]);
    }
    cout << result << endl;
}