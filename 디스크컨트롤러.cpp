#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    int answer = 0, i = 0, time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    sort(jobs.begin(), jobs.end());

    while (!q.empty() || i < jobs.size())
    {
        if (i < jobs.size() && jobs[i][0] <= time)
        {
            q.push(make_pair(jobs[i][1], jobs[i][0]));
            i++;
            continue;
        }
        if (!q.empty())
        {
            time += q.top().first;
            answer += (time - q.top().second);
            q.pop();
        }
        else
            time = jobs[i][0];
    }
    answer /= jobs.size();

    return answer;
}