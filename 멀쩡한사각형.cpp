#include <math.h>

using namespace std;

long long solution(int w, int h)
{
    long long answer = 1;
    int a = w, b = h;
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    long long tmp = w + h - a;
    answer = (long long)w * (long long)h - tmp;

    return answer;
}