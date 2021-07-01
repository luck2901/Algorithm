#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string s;
    string answer="";

    cin >> N >> s;

    for (int i = 0; i < s.size();i++)
    {
        if(s[i]=='J'|| s[i]=='A' || s[i]=='V')
            s[i] = '-';
    }
    for (int i = 0; i < s.size();i++)
    {
        if(s[i]!='-')
            answer += s[i];
    }

    if(!answer.size())
        cout << "nojava" << endl;
    else
        cout << answer << endl;
}