#include <string>
#include <vector>
#include <stack>

using namespace std;

bool test(string s)
{
    stack<char> con;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
            con.push(c);
        else
        {
            if (c == ')' && con.top() == '(')
                con.pop();
            else if (c == '}' && con.top() == '{')
                con.pop();
            else if (c == ']' && con.top() == '[')
                con.pop();
            else
                return false;
        }
    }
    if (!con.empty())
        return false;
    return true;
}

int solution(string s)
{
    int answer = 0;

    if (test(s))
        answer++;

    for (int i = 0; i < s.size() - 1; i++)
    {
        s.push_back(s[0]);
        s.erase(0, 1);
        if (test(s))
            answer++;
    }

    return answer;
}