#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;  cin >> N >> M;

    if (N == 1) cout << 1 << endl;
    else if (N == 2) cout << min(4, (M + 1) / 2);
    else if (N >= 3) {
        if (M <= 6) cout << min(4, M) << endl;
        else cout << M - 2 << endl;
    }
}