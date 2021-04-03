#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, answer = 0;
int result[6];
vector<int> v[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        int idx = i;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if(j==0)
                    break;
                else if (v[j-1][idx] == v[j][k])
                {
                    if (k == 0)
                        idx = 5;
                    else if (k == 1)
                        idx = 3;
                    else if (k == 2)
                        idx = 4;
                    else if (k == 3)
                        idx = 1;
                    else if (k == 4)
                        idx = 2;
                    else
                        idx = 0;
                    break;
                }
            }
            if (idx == 0 || idx == 5)
            {
                result[i] += max(v[j][1], max(v[j][2], max(v[j][3], v[j][4])));
            }
            else if (idx == 1 || idx == 3)
            {
                result[i] += max(v[j][0], max(v[j][2], max(v[j][5], v[j][4])));
            }
            else if (idx == 2 || idx == 4)
            {
                result[i] += max(v[j][0], max(v[j][1], max(v[j][3], v[j][5])));
            }
        }
        answer = max(answer, result[i]);
    }

    cout << answer << endl;
}