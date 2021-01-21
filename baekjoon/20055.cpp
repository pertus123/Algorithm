#include <iostream>
#include <vector>
using namespace std;
int N, K, ans, zeroCnt;
int board[201], visit[201];
vector<int> robots;

void cycle() {
	int tmp = board[2 * N];
	for (int i = 2*N; i > 1; i--) board[i] = board[i - 1];
	board[1] = tmp;

	for (int i = 0; i < robots.size(); i++) {
		visit[robots[i]] = 0;
		robots[i] = robots[i] + 1;
		visit[robots[i]] = 1;
	}
}

void solve() {
	while (++ans) {
		cycle();

		for (int i = 0; i < robots.size(); i++) {
			if (robots[i] == N) {
				visit[robots[i]] = 0;
				robots.erase(robots.begin() + i);
				i--;
				continue;
			}

			int tmp = robots[i];
			if (board[tmp + 1] <= 0 || visit[tmp + 1] == 1) continue;
			visit[tmp] = 0;
			visit[tmp + 1] = 1;
			board[tmp + 1]--;
			if (board[tmp + 1] <= 0) zeroCnt++;
			robots[i] = tmp + 1;

			if (robots[i] == N) {
				visit[robots[i]] = 0;
				robots.erase(robots.begin() + i);
				i--;
			}
		}

		if (visit[1] == 0 && board[1] > 0) { 
			visit[1] = 1;
			board[1]--;
			if (board[1] <= 0)  zeroCnt++;
			robots.push_back(1);
		}

		if (zeroCnt >= K) return;
	}
}

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= 2 * N; i++) scanf("%d", &board[i]);
	solve();
	printf("%d\n", ans);

	return 0;
}