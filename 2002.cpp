#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string.h>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, result = 0;
    cin >> N;
    unordered_map<string, int> m;
    int c[1001];

    for (int i = 0; i < N;i++)
    {
        string s;
        cin >> s;
        m[s] = i;
    }
    for (int i = 0; i < N;i++)
    {
        string s;
        cin >> s;
        c[i] = m[s];
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(c[i] > c[j])
            {
                result++;
                break;
            }
        }
        }

    cout << result << endl;
}