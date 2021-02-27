#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int one = 0, zero = 0;
    bool tag = -1;
    string s; cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1' && tag != 1) {
            one++;
            tag = 1;
        }
        else if (s[i] == '0' && tag != 0) {
            zero++;
            tag = 0;
        }
    }
    cout << min(one, zero) << endl;
}