#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<pair<pair<int, int>, int>> truck;
int moving[2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, M, sum = 0, result = 0; cin >> N >> C >> M; // 마을 수, 트럭 용량, 박스 개수
    for (int i = 0; i < M; i++) {
        int s, r, b; cin >> s >> r >> b;
        truck.push_back({ {r,s},b });
    }
    sort(truck.begin(), truck.end());

    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        int receive = truck[i].first.first;
        int send = truck[i].first.second;
        int box = truck[i].second;
        
        for (int j = send; j < receive; j++)
        {
            sum = max(moving[j], sum);
        }

        sum = min(C - sum, box);
        result += sum;
        for (int j = send; j < receive; j++)
        {
            moving[j] += sum;
        }
    }
    cout << result << endl;
}