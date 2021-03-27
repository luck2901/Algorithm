#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int D, N, minNum = 1987654321;
vector<int> oven;
vector<int> pizza;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D >> N;

    for (int i = 0; i < D; i++)
    {
        int num;
        cin >> num;
        minNum = min(minNum, num);
        oven.push_back(minNum);
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pizza.push_back(num);
    }
    int idx = 0, result = 0;
    for (int i = D - 1; i >= 0; i--)
    {
        if (pizza[idx] <= oven[i])
        {
            if (idx == N - 1)
            {
                result = i + 1;
                break;
            }
            idx++;
        }
    }
    cout << result << endl;
}