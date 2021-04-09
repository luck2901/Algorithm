#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>
#include<set>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, result = 0;
    bool tag = false;
    string table[1001];
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            table[j].append(1,s[j]);
        }
    }

    for (int i = 1; i < R;i++)
    {
        set<string> s;
        for (int j = 0; j < C; j++)
        {
            string tmp = table[j].substr(i, table[j].size() - i);
            if (s.find(tmp) == s.end())
                s.insert(tmp);
            else
            {
                tag = true;
                break;
            }
        }
        if(tag == true)
            break;
        s.clear();
        result++;
    }
    cout << result << endl;
}