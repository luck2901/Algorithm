#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <unordered_map>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <list>

using namespace std;

#define endl "\n"
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> input;

    int N, sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (N == 1)
            break;
        else
            input.push(num);
    }
    while (input.size() > 1)
    {
        int temp = input.top();
        input.pop();
        if (input.empty())
        {
            sum += temp;
            break;
        }
        temp += input.top();
        input.pop();
        sum += temp;
        input.push(temp);
    }
    cout << sum << endl;
}