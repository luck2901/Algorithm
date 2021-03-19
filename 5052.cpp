#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    char s[10010];
    scanf("%d", &t);

    while (t--)
    {
        vector<string> phone;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &s);
            phone.push_back(s);
        }
        bool pin = true;
        sort(phone.begin(), phone.end());

        for (int i = 0; i < n - 1; i++)
        {
            int current = phone[i].length();
            int next = phone[i + 1].length();
            if (current >= next)
                continue;

            if (phone[i + 1].substr(0, current) == phone[i])
            {
                pin = false;
                printf("NO\n");
                break;
            }
        }
        if (pin == true)
            printf("YES\n");
    }
}