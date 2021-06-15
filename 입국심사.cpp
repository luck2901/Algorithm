#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long left = 0;
    long long right = 0;
    long long mid = 0;

    for (int i = 0; i < times.size(); i++)
        right = max((long long)times[i], right);

    right *= n;

    while (left <= right)
    {
        mid = (left + right) / 2;

        long long sum = 0;
        for (int i = 0; i < times.size(); i++)
            sum += (mid / times[i]);

        if (sum >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
            left = mid + 1;
    }

    return answer;
}