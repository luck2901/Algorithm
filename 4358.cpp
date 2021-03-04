#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

map <string, double>tree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(4);

    string s; int cnt = 0;
    while (getline(cin,s)) {
        tree[s] += 1;
        cnt++;
    }
    for (auto i : tree)
        cout << i.first << i.second / cnt * 100 << endl;
}