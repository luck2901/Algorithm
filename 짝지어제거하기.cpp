#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> con;

    for (int i = 0; i < s.size(); i++)
    {
        if (!con.empty() && con.top() == s[i])
            con.pop();
        else
            con.push(s[i]);
    }
    if (con.size() == 0)
        answer = 1;

    return answer;
}