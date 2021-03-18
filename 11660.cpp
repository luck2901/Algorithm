#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;
#define endl "\n"

int arr[1025][1025];
int sumarr[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            sumarr[i][j] = sumarr[i - 1][j] + sumarr[i][j - 1] - sumarr[i-1][j-1]  + arr[i][j];
        }

        int x1, y1, x2, y2;
        int result;
        for (int i = 0; i < M; i++)
        {
            cin >> y1 >> x1 >> y2 >> x2;
            result = sumarr[y2][x2] - sumarr[y1 - 1][x2] - sumarr[y2][x1 - 1] + sumarr[y1 - 1][x1 - 1];
            cout << result << endl;
        }
}