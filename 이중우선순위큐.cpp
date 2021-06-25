#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minNum;
    priority_queue<int, vector<int>, less<int>> maxNum;

    int cnt = 0;
    int idx = operations.size();

    for (int i = 0; i < idx; i++)
    {
        if (operations[i][0] == 'I')
        {
            int num = stoi(operations[i].substr(2));
            minNum.push(num);
            maxNum.push(num);
            cnt++;
        }
        else if (operations[i][0] == 'D' && cnt != 0)
        {
            if (operations[i][2] == '1')
            {
                cnt--;
                maxNum.pop();
            }
            else if (operations[i][2] == '-')
            {
                cnt--;
                minNum.pop();
            }
        }
        if (cnt == 0)
        {
            while (!minNum.empty())
            {
                minNum.pop();
                maxNum.pop();
            }
        }
    }
    if (cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxNum.top());
        answer.push_back(minNum.top());
    }

    return answer;
}