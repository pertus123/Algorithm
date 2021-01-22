#include <iostream>
using namespace std;
int board[101][101], visit[101][101];
int N, M, R, ans;
int d[][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main() {
	scanf("%d %d %d", &N, &M, &R);

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			scanf("%d", &board[i][j]);

	int X, Y, dir;
	char D;
	while (R--) {
		scanf("%d %d %c", &X, &Y, &D);

		if (D == 'E') dir = 0;
		else if (D == 'W') dir = 1;
		else if (D == 'S') dir = 2;
		else dir = 3;
		if (visit[X][Y] == 0) {
			int boardCnt = board[X][Y];
			visit[X][Y] = 1;
			ans++;
			X = X + d[dir][0];
			Y = Y + d[dir][1];

			for (int i = 1; i < boardCnt; i++) {
				if (X < 1 || Y < 1 || X > N || Y > M) break;
				if (visit[X][Y] == 1) {
					X = X + d[dir][0];
					Y = Y + d[dir][1];
					continue;
				}

				if (board[X][Y] > boardCnt - i) {
					i = 0;
					boardCnt = board[X][Y];
				}

				visit[X][Y] = 1;
				ans++;

				X = X + d[dir][0];
				Y = Y + d[dir][1];
			}
		}

		scanf(" %d %d", &X, &Y);
		visit[X][Y] = 0;
	}

	printf("%d\n", ans);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j] == 0) printf("S ");
			else printf("F ");
		}
		printf("\n");
	}

	return 0;
}