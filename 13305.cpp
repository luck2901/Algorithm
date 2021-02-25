#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

#define ll long long

ll coin[100001];
ll dis[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;

    for (int i = 0; i < N - 1; i++)
        cin >> dis[i];
    
    for (int i = 0; i < N; i++)
        cin >> coin[i];

    ll min_coin = coin[0];
    ll result = 0;
    for (int i = 0; i < N - 1; i++)
    {
        min_coin = min(min_coin, coin[i]);
        result += (min_coin * dis[i]);
    }

    cout << result << endl;
}