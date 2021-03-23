#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int F, S, G, U, D ; //총 층수, 강호, 스타트링크, 위버튼, 아래버튼
bool check[1000001];

int bfs(){
    queue<pair<int,int> > q;
    check[S] = true;
    q.push(make_pair(S, 0));
    while(!q.empty())
    {
        int c = q.front().first;
        int cnt = q.front().second;
        if(c == G)
            return cnt;
        int nu = c + U;
        int nd = c - D;
        q.pop();
        if (nu <= F && nu > 0 && !check[nu])
        {
            q.push(make_pair(nu, cnt+1));
            check[nu] = true;
        }
        if(nd > 0 && nd<=F && !check[nd])
        {
            q.push(make_pair(nd, cnt + 1));
            check[nd] = true;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> F >> S >> G >> U >> D;

    int result = bfs();

    if(result == -1)
        cout << "use the stairs" << endl;
    else cout << result << endl;
}