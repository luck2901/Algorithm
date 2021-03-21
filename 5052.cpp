#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

vector<string> phone;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            phone.push_back(s);
        }
        sort(phone.begin(), phone.end());
        bool tag = true;
        for (int i = 0; i < n - 1; i++)
        {
            int first = phone[i].length();
            int second = phone[i+1].length();
            if(first >= second)
                continue;
            if(phone[i+1].substr(0,first)==phone[i])
            {
                tag = false;
                break;
            }
        }
        phone.clear();
        if (tag == true)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
}