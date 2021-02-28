#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define MAX 32001
int N, M;
int inDegree[MAX];
vector<int> v[MAX];
int result[MAX];

void topology() {
	priority_queue<int, vector<int>, greater<int> > q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int x = q.top();
		q.pop();
		cout << x << " ";
		for (auto next : v[x])
			if (--inDegree[next] == 0)
				q.push(next);
	}
}

int main() {

	cin >> N >> M;

	while (M--) {
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		inDegree[b]++;
	}

	topology();
}