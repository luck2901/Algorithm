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

    string in;

    cin >> in;

    int inSize = in.size();

    for (int i = 0; i < inSize; i++)
    {
        int num = stoi(in.substr(0, i + 1));
        int end;
        string tmp = "";
        bool tag = false;
        for (int j = num;; j++)
        {
            tmp += to_string(j);
            if (tmp != in.substr(0, tmp.size()))
            {
                tag = true;
                break;
            }
            if (tmp.size() == in.size())
            {
                end = j;
                break;
            }
        }
        if (tag == false)
        {
            cout << num << " " << end << endl;
            break;
        }
    }
}