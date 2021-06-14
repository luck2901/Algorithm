#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int arr[100001];

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<int, int> m;
    int cnt = 0, num = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
            cnt++;
        else if (s[i] == '}' && cnt == 2)
        {
            m[num] += 1;
            num = -1;
            cnt--;
        }
        else if (s[i] == ',' && cnt == 2)
        {
            m[num] += 1;
            num = -1;
        }
        else if ('0' <= s[i] && s[i] <= '9')
        {
            if (num == -1)
                num = (s[i] - '0');
            else
            {
                num *= 10;
                num += (s[i] - '0');
            }
        }
    }
    for (auto i : m)
    {
        arr[i.second] = i.first;
    }

    for (int i = m.size(); i >= 1; i--)
        answer.push_back(arr[i]);

    return answer;
}