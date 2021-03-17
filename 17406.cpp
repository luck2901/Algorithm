#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N, M, K, minvalue = 987654321;
int arr[51][51];
int rarr[51][51];
int check[51];
vector<pair<pair<int, int>, int> > v;

void sequence()
{
    do
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                arr[i][j] = rarr[i][j];
        for (int i = 0; i < K; i++)
        {
            int r = v[i].first.first - 1;
            int c = v[i].first.second - 1;
            int s = v[i].second;
            int cnt = 0, idx = 1, line = 3;
            int y, x;
            while (cnt != s)
            {
                int tmp = arr[r - idx][c - idx];
                y = r - idx;
                x = c - idx;
                for (int j = x + 1; j < x + line; j++)
                {
                    int tmp2 = arr[y][j];
                    arr[y][j] = tmp;
                    tmp = tmp2;
                }
                x = x + line - 1;
                for (int j = y + 1; j < y + line; j++)
                {
                    int tmp2 = arr[j][x];
                    arr[j][x] = tmp;
                    tmp = tmp2;
                }
                y = y + line - 1;
                for (int j = x - 1; j > x - line; j--)
                {
                    int tmp2 = arr[y][j];
                    arr[y][j] = tmp;
                    tmp = tmp2;
                }
                x = x - line + 1;
                for (int j = y - 1; j > y - line; j--)
                {
                    int tmp2 = arr[j][x];
                    arr[j][x] = tmp;
                    tmp = tmp2;
                }
                cnt++;
                line += 2;
                idx += 1;
            }
        }
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = 0; j < M; j++)
            {
                sum += arr[i][j];
            }
            minvalue = min(sum, minvalue);
        }
    } while (next_permutation(v.begin(), v.end()));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> rarr[i][j];
    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back(make_pair(make_pair(r, c), s));
    }

    sort(v.begin(), v.end());
    sequence();

    cout << minvalue << endl;
}