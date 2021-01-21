#include <iostream>
using namespace std;
int N, Q, board[250010];

int binary(int st, int ed, int mid) {
	while (st <= ed) {
		int pit = (st + ed) / 2;
		if (board[pit + 1] < mid && board[pit] >= mid) return pit;
		if (board[pit] < mid) ed = pit - 1;
		else st = pit + 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%d", &board[i]);

	int x, y;
	for (int q = 0; q < Q; q++) {
		int ans = 0;
		scanf("%d %d", &x, &y);
		if (board[y] < x) ans = 0;
		else {
			int a = binary(y, N+1, x);
			ans += a - y + 1;
			ans += board[y] - x + 1;
			ans--;
		}
		printf("%d\n", ans);
	}

	return 0;
}