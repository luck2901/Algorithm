#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

int root[100001];

int find(int x)
{
    if(root[x]==x)
        return x;
    else
        return root[x] = find(root[x]);
}

void unionf(int y, int x)
{
    y = find(y);
    x = find(x);

    root[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, P, g;
    int answer = 0;

    cin >> G >> P;

    for (int i = 0; i <= G;i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < P; i++)
    {
        cin >> g;
        if (find(g) != 0)
        {
            unionf(find(g), find(g)-1);
            answer++;
        }
        else
            break;
    }

    cout << answer << endl;
}