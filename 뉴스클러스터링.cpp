#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool check[2001];

int solution(string str1, string str2)
{
    int answer = 0;

    vector<string> v[2];

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (str1[i] >= 'a' && 'z' >= str1[i] && 'a' <= str1[i + 1] && str1[i + 1] <= 'z')
            v[0].push_back(str1.substr(i, 2));
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (str2[i] >= 'a' && 'z' >= str2[i] && 'a' <= str2[i + 1] && str2[i + 1] <= 'z')
            v[1].push_back(str2.substr(i, 2));
    }

    if (v[0].empty() && v[1].empty())
        return 65536;

    int uni = 0, intersection = 0;

    for (int i = 0; i < v[0].size(); i++)
    {
        for (int j = 0; j < v[1].size(); j++)
        {
            if (check[j])
                continue;
            if (v[0][i] == v[1][j])
            {
                check[j] = 1;
                intersection++;
                break;
            }
        }
    }
    uni = v[0].size() + v[1].size() - intersection;

    if (uni == 0)
        return 65536;

    double tmp = (double)intersection / (double)uni;

    answer = tmp * 65536;

    return answer;
}