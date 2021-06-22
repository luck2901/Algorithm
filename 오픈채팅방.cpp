#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<pair<string, string>> v;
    map<string, string> data;

    for (int i = 0; i < record.size(); i++)
    {
        string str[3];
        string tmp = "";
        int idx = 0;
        for (int j = 0; j < record[i].size(); j++)
        {
            if (record[i][j] == ' ')
            {
                str[idx++] = tmp;
                tmp = "";
            }
            else
                tmp += record[i][j];
        }
        str[idx] = tmp;
        if (str[0] == "Enter" || str[0] == "Change")
            data[str[1]] = str[2];

        if (str[0] == "Enter" || str[0] == "Leave")
            v.push_back(make_pair(str[1], str[0]));
    }

    for (int i = 0; i < v.size(); i++)
    {
        string id = v[i].first;
        string tmp = data[id];
        if (v[i].second == "Enter")
            tmp += "님이 들어왔습니다.";
        else if (v[i].second == "Leave")
            tmp += "님이 나갔습니다.";

        answer.push_back(tmp);
    }

    return answer;
}