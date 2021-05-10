#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    }
    for (int i = 0; i < new_id.size();)
    {
        char c = new_id[i];
        if ((c >= 'a' && c <= 'z') || c == '.' || c == '_' || c == '-' || (c >= '0' && c <= '9'))
        {
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }

    for (int i = 0; i < new_id.size() - 1;)
    {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
            new_id.erase(new_id.begin() + i);
        else
            i++;
    }

    if (new_id[0] == '.')
        new_id.erase(new_id.begin());

    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.size() - 1);

    if (new_id.size() == 0)
        new_id.push_back('a');

    if (new_id.size() >= 16)
        new_id = new_id.substr(0, 15);

    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.begin() + new_id.size() - 1);

    while (new_id.size() <= 2)
        new_id.push_back(new_id[new_id.size() - 1]);

    answer = new_id;

    return answer;
}