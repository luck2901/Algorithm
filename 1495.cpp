#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int N, S, M;
vector<int> v;
int check[1001];
int idx = 0, result = 0;

void bfs()
{
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int plusq = q.front() + v[idx];
            int minusq = q.front() - v[idx];
            q.pop();
            if (plusq <= M && plusq >= 0 && !check[plusq])
            {
                q.push(plusq);
                check[plusq] = 1;
            }
            if (minusq <= M && minusq >= 0 && !check[minusq])
            {
                q.push(minusq);
                check[minusq] = 1;
            }
        }
        memset(check, 0, sizeof(check));
        idx++;
        if(idx == N && !q.empty())
        {
            while(!q.empty())
            {
                result = max(q.front(), result);
                q.pop();
            }
            return;
        }
    }
    result = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> M;
    for (int i = 0; i < N;i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    bfs();

    cout << result << endl;
}