#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

void bfs(int num, int idx, int cnt, vector<string> &ans, vector<bool> &check, vector<char> &tmp, vector<char> candidate, vector<string> orders, int &allcnt)
{
    if (cnt == num)
    {
        string tmps = "";
        int tmpcnt = 0;
        for (int i = 0; i < tmp.size(); i++)
            tmps += tmp[i];
        for (int j = 0; j < orders.size(); j++)
        {
            bool tag = true;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (orders[j].find(tmp[i]) == -1)
                {
                    tag = false;
                    break;
                }
            }
            if (tag == true)
                tmpcnt++;
        }
        if (tmpcnt < 2 || tmpcnt < allcnt)
            return;
        if (tmpcnt == allcnt)
            ans.push_back(tmps);
        else if (tmpcnt > allcnt)
        {
            allcnt = tmpcnt;
            ans.clear();
            ans.push_back(tmps);
        }
        return;
    }
    for (int i = idx; i < candidate.size(); i++)
    {
        if (check[candidate[i] - 'A'])
            continue;
        check[candidate[i] - 'A'] = 1;
        tmp.push_back(candidate[i]);
        bfs(num, i, cnt + 1, ans, check, tmp, candidate, orders, allcnt);
        tmp.pop_back();
        check[candidate[i] - 'A'] = 0;
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    vector<char> candidate;
    map<char, int> visit;

    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].size(); j++)
        {
            char C = orders[i][j];
            if (visit[C] == 0)
                visit[C]++;
            else if (visit[C] == 1)
            {
                visit[C]++;
                candidate.push_back(C);
            }
        }
    }

    sort(candidate.begin(), candidate.end());

    for (int i = 0; i < course.size(); i++)
    {
        int allcnt = 0;
        vector<bool> check(27, false);
        vector<char> tmp;
        vector<string> ans;

        bfs(course[i], 0, 0, ans, check, tmp, candidate, orders, allcnt);
        for (int j = 0; j < ans.size(); j++)
            answer.push_back(ans[j]);
    }

    sort(answer.begin(), answer.end())

        return answer;
}