#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> num;
vector<char> numop;
vector<char> op;
vector<char> seq;
bool check[3];
long long ans = -1;

void go()
{
    if (seq.size() == op.size())
    {
        vector<long long> tmpnum = num;
        vector<char> tmpop = numop;
        for (int i = 0; i < seq.size(); i++)
        {
            for (int j = 0; j < tmpop.size(); j++)
            {
                if (tmpop[j] == seq[i])
                {
                    if (seq[i] == '+')
                        tmpnum[j] = tmpnum[j] + tmpnum[j + 1];
                    else if (seq[i] == '-')
                        tmpnum[j] = tmpnum[j] - tmpnum[j + 1];
                    else if (seq[i] = '*')
                        tmpnum[j] = tmpnum[j] * tmpnum[j + 1];
                    tmpnum.erase(tmpnum.begin() + j + 1);
                    tmpop.erase(tmpop.begin() + j);
                    j--;
                }
            }
        }
        ans = max(ans, abs(tmpnum[0]));
        return;
    }
    for (int i = 0; i < op.size(); i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        seq.push_back(op[i]);
        go();
        seq.pop_back();
        check[i] = false;
    }
}

long long solution(string expression)
{
    long long answer = 0;
    int sum = 0;
    for (int i = 0; i < expression.size(); i++)
    {
        char input = expression[i];
        if (input >= '0' && input <= '9')
        {
            if (sum != 0)
                sum *= 10;
            sum += (input - '0');
        }
        else if (input == '*' || input == '+' || input == '-')
        {
            if (find(op.begin(), op.end(), input) == op.end())
                op.push_back(input);
            numop.push_back(input);
            num.push_back(sum);
            sum = 0;
        }
    }
    num.push_back(sum);

    go();

    answer = ans;

    return answer;
}