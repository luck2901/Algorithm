#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, n;
    deque<int> d;

    cin >> tc;

    while(tc--)
    {
        string p, num, tmp="";
        bool tag = false, breaktag=false;

        cin >> p;

        cin >> n;
        cin >> num;

        for (int i = 0; i < num.size();i++)
        {
            if(tmp!="" && (num[i]==',' || num[i]==']'))
            {
                d.push_back(stoi(tmp));
                tmp = "";
            }
            else if (num[i] >= '0' && num[i] <= '9')
            {
                tmp += num[i];
            }
        }
        for (int i = 0; i < p.size();i++)
        {
            if(p[i]=='D')
            {
                if(d.size()==0)
                {
                    cout << "error"<<endl;
                    breaktag = !breaktag;
                    break;
                }
                else if(tag == false)
                {
                    d.pop_front();
                }
                else if(tag == true)
                {
                    d.pop_back();
                }
            }
            else if(p[i]=='R')
            {
                tag = !tag;
            }
        }
        if (!breaktag)
        {
            cout << '[';
            int cnt = d.size();
            for (int j = 0; j < cnt; j++)
            {
                if(tag==false)
                {
                    if (j != cnt - 1)
                        cout << d.front() << ",";
                    else
                        cout << d.front();
                    d.pop_front();
                }
                else if (tag == true)
                {
                    if (j != cnt - 1)
                        cout << d.back() << ",";
                    else
                        cout << d.back();
                    d.pop_back();
                }
            }
            cout << "]" << endl;
        }
    }
}