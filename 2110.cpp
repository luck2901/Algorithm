#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int>Home;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C; cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        Home.push_back(num);
    }
    sort(Home.begin(), Home.end());
    int start = 1;
    int end = Home.back();
    int result = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int before = 0;
        int cnt = 1;
        for (int after = 1; after < N; after++) {
            if (Home[after] - Home[before] >= mid)
            {
                cnt++;
                before = after;
            }
        }
        if (cnt >= C) {
            start = mid + 1;
            result = mid;
        }
        else end = mid - 1;

    }
    cout << result << endl;
}