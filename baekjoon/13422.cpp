#include <iostream>
using namespace std;
int T;
int board[200002];
int N, M, K;
int s, e, ans;
long long int sum;

void init() {
	ans = 0, sum = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &board[i]);
	}

	for (int i = 0; i < N; i++) {
		board[N + i] = board[i];
	}

	for (int i = 0; i < M; i++) {
		sum += board[i];
	}
	s = 0;
	e = M - 1;

}

int main() {
	scanf("%d", &T);

	while (T--) {
		init();

		if (N == M) {
			if (sum < K) {
				ans = 1;
			}
			else {
				ans = 0;
			}

		}
		else {
			for (int i = 0; i < N; i++) {
				if (sum < K) {
					ans++;
				}
				sum -= board[s++];
				sum += board[++e];
			}
		}

		printf("%d\n", ans);
	}

}