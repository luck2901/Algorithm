#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string.h>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int A[51];
int B[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(B, B + N);
    sort(A, A + N, compare);

    int sum = 0;

    for (int i = 0; i < N; i++)
        sum += (A[i] * B[i]);
    
    cout << sum << endl;
}