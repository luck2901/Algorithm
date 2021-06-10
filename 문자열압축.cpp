#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)
    {
        int cnt = 1;
        string leftNum = s.substr(0, i);
        string tmp;
        for (int j = i; j < s.length(); j += i)
        {
            string rightNum = s.substr(j, i);
            if (leftNum == rightNum)
            {
                cnt++;
            }
            else
            {
                if (cnt > 1)
                    tmp += to_string(cnt);
                tmp += leftNum;
                leftNum = rightNum;
                cnt = 1;
            }
        }
        if (cnt > 1)
            tmp += to_string(cnt);
        tmp += leftNum;
        answer = min(answer, (int)tmp.size());
    }

    return answer;
}