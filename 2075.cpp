#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

priority_queue<int, vector<int>, greater<int> > q;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
        for (int j = 0; j < N;j++)
        {
            int num;
            cin >> num;
            q.push(num);
            if(i>=1)
                q.pop();
        }
    cout << q.top() << endl;


}