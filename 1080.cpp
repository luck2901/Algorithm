#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int A[51][51];
int B[51][51];

void change(int y, int x)
{
    for (int i = y; i < y + 3; i++)
        for (int j = x; j < x + 3; j++)
            A[i][j] ? A[i][j] = 0 : A[i][j] =1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0; cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < M; j++)
        {
            A[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < M; j++)
        {
            B[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N - 2; i++)
        for (int j = 0; j < M - 2; j++)
        {
            if (A[i][j] != B[i][j])
            {
                change(i, j);
                cnt++;
            }
        }

    bool tag = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != B[i][j])
            {
                tag = 1;
                cnt = -1;
                break;
            }
        }
        if (tag) break;
    }
    cout << cnt << endl;
}