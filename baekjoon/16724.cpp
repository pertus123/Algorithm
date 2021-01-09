#include <iostream>
using namespace std;
char board[1001][1001];
int visit[1001][1001];
int N, M;
int ans;

void dfs(int x, int y, int cnt) {
	if (x < 0 || y < 0 || x >= N || y >= M) {
		ans++;
		return;
	}
	if (visit[x][y] == cnt) {
		ans++;
		return;
	}
	if (visit[x][y] != 0) {
		return;
	}
	
	visit[x][y] = cnt;

	if (board[x][y] == 'D') {
		dfs(x + 1, y, cnt);
	}
	else if (board[x][y] == 'U') {
		dfs(x - 1, y, cnt);
	}
	else if (board[x][y] == 'R') {
		dfs(x, y + 1, cnt);
	}
	else {
		dfs(x, y - 1, cnt);
	}
}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}