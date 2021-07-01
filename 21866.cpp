#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int score[9] = {100, 100, 200, 200, 300, 300, 400, 400, 500};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;

    for (int i = 0; i < 9; i++)
    {
        int num;
        cin >> num;
        if (num <= score[i])
            sum += num;
        else
        {
            cout << "hacker" << endl;
            return 0;
        }
    }
    if (sum >= 100)
        cout << "draw" << endl;
    else
        cout << "none" << endl;
}