#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> m;
unordered_map<string, string> parent;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    m["-"] = 0;
    for (int i = 0; i < enroll.size(); i++)
    {
        m[enroll[i]] = 0;
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        string me = seller[i];
        int coin = amount[i] * 100;
        while (me != "-" && coin / 10 >= 1)
        {
            m[me] += (coin - coin / 10);
            coin = coin / 10;
            me = parent[me];
        }
        m[me] += (coin);
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(m[enroll[i]]);
    }

    return answer;
}