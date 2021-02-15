#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

# define PLAYER_NUM 10

bool select[PLAYER_NUM];
int order[PLAYER_NUM];
int player[51][PLAYER_NUM];
int idx = 1;
int out = 0;
int score = 0;
int max_score = 0;
int inning;


void Play() {
	idx = 1;
	score = 0;
	int Base[4];
	for (int i = 1; i <= inning; i++) {
		memset(Base, 0, sizeof(Base));
		bool next = false;
		out = 0;
		while (true) {
			for (int j = idx; i < PLAYER_NUM; j++)
			{
				int p = player[i][order[j]];

				if (p == 0) out++;
				else if (p == 1) {
					for (int f = 3; f >= 1; j--) {
						if (Base[f] == 1)
						{
							if (f == 3)
							{
								Base[f] = 0;
								score++;
							}
							else {
								Base[f + 1] = 1;
								Base[f] = 0;
							}
						}
					}
					Base[1] = 1;
				}
				else if (p == 2) {
					for (int f = 3; f >= 1; f--) {
						if (Base[f] == 1) {
							if (f == 3 || f == 2) {
								Base[f] = 0;
								score++;
							}
							else {
								Base[f + 2] = 1;
								Base[f] = 0;
							}
						}
					}
					Base[2] = 1;
				}
				else if (p == 3) {
					for (int f = 3; f >= 1; f--) {
						if (Base[f] == 1) {
							Base[f] = 0;
							score++;
						}
					}
					Base[3] = 1;
				}
				else if (p == 4) {
					for (int f = 3; f >= 1; f--) {
						if (Base[f] == 1) {
							Base[f] = 0;
							score++;
						}
					}
					score++;
				}
				if (out == 3) {
					idx = j + 1;
					if (idx == PLAYER_NUM) idx = 1;

					next = true;
					break;
				}
			}
			if (next == true) break;
			idx = 1;
		}
	}
	max_score = max(max_score, score);
}

void DFS(int cnt) {
	if (cnt == PLAYER_NUM) {
		Play();
		return;
	}
	for (int i = 1; i < PLAYER_NUM; i++)
	{
		if (select[i] == true) continue;
		select[i] = true;
		order[i] = cnt;
		DFS(cnt + 1);
		select[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> inning;

	for (int i = 1; i <= inning; i++)
		for (int j = 1; j < PLAYER_NUM; j++)
			cin >> player[i][j];

	order[4] = 1;
	select[4] = true;
	DFS(2);

	cout << max_score << endl;
}