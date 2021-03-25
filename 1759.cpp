#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<map>
#include <string.h>

using namespace std;

#define endl "\n"

int L, C;
vector<char> v;
map<string, int> visited;
int checking[30];

void dfs(int cnt, string s, int ja, int mo)
{
    if (s.size() == L)
    {
        if(ja>=2 && mo>=1)
            cout << s << endl;
    }
    for (int i = cnt; i < C;i++)
    {
        if(v[i]=='a'|| v[i]=='e'|| v[i]=='i'||v[i]=='o'||v[i]=='u')
            dfs(i + 1, s + v[i], ja, mo + 1);
        else
            dfs(i + 1, s + v[i], ja + 1, mo);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for (int i = 0; i < C;i++)
    {
        char s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    dfs(0, "", 0, 0);
}