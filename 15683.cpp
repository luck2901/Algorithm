#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int room[9][9];
vector<pair<int, int> > v[6];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
            if (room[i][j] >= 1 && room[i][j] <= 5)
                v[room[i][j]].push_back(make_pair(i, j));
        }
}