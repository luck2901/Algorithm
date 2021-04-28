#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<int> v;
vector<int> tmp;
set<int> s;
int ans = 0;
bool check[8];
bool isPrime(int num)
{
    int cnt = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cnt++;
        if (cnt >= 2 && i != num)
            return false;
    }
    if (cnt == 2)
        return true;
    else
        return false;
}
void go(int cnt)
{
    if (cnt >= 1)
    {
        int num = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            num += tmp[i];
            if (i == tmp.size() - 1)
                break;
            num *= 10;
        }
        if (s.find(num) == s.end())
        {
            s.insert(num);
            if (isPrime(num))
                ans++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            tmp.push_back(v[i]);
            go(cnt + 1);
            tmp.pop_back();
            check[i] = false;
        }
    }
}

int solution(string numbers)
{
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++)
        v.push_back(numbers[i] - '0');

    sort(v.begin(), v.end());

    go(0);

    answer = ans;

    return answer;
}