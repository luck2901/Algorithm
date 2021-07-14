#include <string>
#include <vector>

using namespace std;

bool check[46];

int ranking(int correct)
{
    switch (correct)
    {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int correct = 0;
    int zero = 0;

    for (int i = 0; i < win_nums.size(); i++)
        check[win_nums[i]] = true;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (check[lottos[i]])
            correct++;
        else if (lottos[i] == 0)
            zero++;
    }

    answer.push_back(ranking(correct + zero));
    answer.push_back(ranking(correct));

    return answer;
}