#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string t)
{
    int s = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '(')
            s++;
        else
        {
            if (!s)
                return false;
            s--;
        }
    }
    return true;
}

string recursive(string w)
{
    string u = "", v = "";
    if (w == "")
        return w;
    int cnt = 0;
    for (int i = 0; i < w.size(); i++)
    {
        if (w[i] == '(')
            cnt++;
        else if (w[i] == ')')
            cnt--;
        if (cnt == 0)
        {
            u = w.substr(0, i + 1);
            v = w.substr(i + 1);
            break;
        }
    }
    if (check(u))
        return u + recursive(v);
    else
    {
        string tmp = "(";
        tmp = tmp + recursive(v) + ')';
        u = u.substr(1);
        u.pop_back();
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == ')')
                tmp += '(';
            else
                tmp += ')';
        }
        return tmp;
    }
}

string solution(string p)
{
    string answer = "";

    answer = recursive(p);

    return answer;
}