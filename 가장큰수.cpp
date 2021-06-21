#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> temp;

    for (int i : numbers)
        temp.push_back(to_string(i));

    sort(temp.begin(), temp.end(), compare);

    if (temp[0] == "0")
        return "0";

    for (string s : temp)
        answer += s;

    return answer;
}