#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, cnt = 0;
    cin >> N >> K;
    stack<int> num;
    vector<int> result;

    string s;
    cin >> s;
    num.push(s[0] - '0');
    for (int i = 1; i < N; i++)
    {
        int tmp = s[i] - '0';
        if (cnt == K || num.top() >= tmp)
            num.push(tmp);
        else
        {
            while (num.top() < tmp && cnt != K)
            {
                num.pop();
                cnt++;
                if (num.empty())
                    break;
            }
            num.push(tmp);
        }
    }
    while (cnt != K)
    {
        num.pop();
        cnt++;
    }
    while (!num.empty())
    {
        result.push_back(num.top());
        num.pop();
    }
    for (auto i = result.rbegin(); i != result.rend(); i++)
        cout << *i;
    cout << endl;
}