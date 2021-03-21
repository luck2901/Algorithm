#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"

vector<int> hunter;
vector<pair<int, int> > animal;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, L;

    cin >> M >> N >> L;
    for (int i = 0; i < M;i++)
    {
        int num;
        cin >> num;
        hunter.push_back(num);
    }
    for (int i = 0; i < N;i++)
    {
        int x, y;
        cin >> x >> y;
        animal.push_back(make_pair(x, y));
    }
    sort(hunter.begin(), hunter.end());
    sort(animal.begin(), animal.end());

    int j = 0, cnt = 0;
    for (int i = 0; i < M; i++)
    {
        for (j; j < N;j++)
        {
            if (abs(hunter[i] - animal[j].first) + animal[j].second <= L)
                cnt++;
            else if(i < M-1 && abs(hunter[i]-animal[j].first) > abs(hunter[i+1]-animal[j].first))
                break;
        }
    }
    cout << cnt << endl;
}