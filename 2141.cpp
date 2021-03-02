#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef long long ll;
vector<pair<int, int>>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, tag = 0; cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int x, a; cin >> x >> a;
        v.push_back({ x,a });
        sum += a;
    }
    sort(v.begin(), v.end());
    if (sum % 2 == 1) tag = 1;
    sum = ceil(sum/2);
    ll temp = 0;
    int i = 0;
    if (tag == 0)
        while (temp < sum) {
            temp += v[i].second;
            i++;
        }
    else
        while (temp <= sum) {
            temp += v[i].second;
            i++;
        }
    cout << v[i - 1].first << endl;

}