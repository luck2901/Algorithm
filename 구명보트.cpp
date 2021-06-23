#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0, sum = 0, idx = 0;

    sort(people.begin(), people.end());

    while (idx < people.size())
    {
        int back = people.back();
        people.pop_back();
        if (people[idx] + back <= limit)
        {
            answer++;
            idx++;
        }
        else
            answer++;
    }

    return answer;
}