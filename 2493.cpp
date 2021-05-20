#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    stack<pair<int, int>> s;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        while (!s.empty())
        {
            if (s.top().second > num)
            {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if (s.empty())
            cout << "0 ";
        s.push(make_pair(i + 1, num));
    }
}