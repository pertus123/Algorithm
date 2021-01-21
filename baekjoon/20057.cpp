#include<iostream>
using namespace std;
int board[501][501];
int N, ans, x, y;
int gab, p1, p2, p5, p7, p10;

void init() {
	 gab = board[x][y];
	 p1 = gab * 0.01;
	 p2 = gab * 0.02;
	 p5 = gab * 0.05;
	 p7 = gab * 0.07;
	 p10 = gab * 0.1;
	 board[x][y] = 0;
}

void left() {
	init();

	board[x + 1][y] += p7;
	board[x - 1][y] += p7;

	board[x + 1][y+1] += p1;
	board[x - 1][y+1] += p1;

	if (x + 2 > N + 1) ans += p2;
	else board[x + 2][y] += p2;
	if (x - 2 < 0) ans += p2;
	else board[x - 2][y] += p2;

	if (y - 2 < 0) ans += p5;
	else board[x ][y-2] += p5;

	board[x + 1][y-1] += p10;
	board[x - 1][y-1] += p10;

	board[x][y - 1] += gab - (p1 * 2 + p2 * 2 + p5 + p7 * 2 + p10 * 2);
}
void right() {
	init();

	board[x + 1][y] += p7;
	board[x - 1][y] += p7;

	board[x + 1][y - 1] += p1;
	board[x - 1][y - 1] += p1;

	if (x + 2 > N + 1) ans += p2;
	else board[x + 2][y] += p2;
	if (x - 2 < 0) ans += p2;
	else board[x - 2][y] += p2;

	if (y + 2 > N+1) ans += p5;
	else board[x][y + 2] += p5;

	board[x + 1][y+1] += p10;
	board[x - 1][y+1] += p10;

	board[x][y + 1] += gab - (p1 * 2 + p2 * 2 + p5 + p7 * 2 + p10 * 2);
}
void up() {
	init();

	board[x][y+1] += p7;
	board[x][y-1] += p7;

	board[x + 1][y + 1] += p1;
	board[x + 1][y - 1] += p1;

	if (y + 2 > N + 1) ans += p2;
	else board[x][y+2] += p2;
	if (y - 2 < 0) ans += p2;
	else board[x][y-2] += p2;

	if (x - 2 < 0) ans += p5;
	else board[x-2][y] += p5;

	board[x - 1][y + 1] += p10;
	board[x - 1][y - 1] += p10;

	board[x-1][y] += gab - (p1 * 2 + p2 * 2 + p5 + p7 * 2 + p10 * 2);
}
void down() {
	init();

	board[x][y + 1] += p7;
	board[x][y - 1] += p7;

	board[x - 1][y + 1] += p1;
	board[x - 1][y - 1] += p1;

	if (y + 2 > N + 1) ans += p2;
	else board[x][y + 2] += p2;
	if (y - 2 < 0) ans += p2;
	else board[x][y - 2] += p2;

	if (x + 2 > N+1) ans += p5;
	else board[x + 2][y] += p5;

	board[x + 1][y + 1] += p10;
	board[x + 1][y - 1] += p10;

	board[x + 1][y] += gab - (p1 * 2 + p2 * 2 + p5 + p7 * 2 + p10 * 2);
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 	scanf("%d", &board[i][j]);

	y = x  = N / 2 + 1;
	
	for (int tc = 1; tc <= N; tc++) {
		if (tc % 2 == 1) {
			for (int i = 0; i < tc; i++) {
				y--; 
				left();
				if (tc == N && i == tc - 2) break;
			}
			if (tc == N) break;
			for (int i = 0; i < tc; i++) {
				x++;
				down();
			}
		}
		else {
			for (int i = 0; i < tc; i++) {
				y++;
				right();
			}
			for (int i = 0; i < tc; i++) {
				x--;
				up();
			}	
		}
	}

	for (int i = 0; i <= N+1; i++) {
		ans += board[0][i];
		ans += board[i][0];
		ans += board[N+1][i];
		ans += board[i][N+1];
	}
	ans -= board[0][0];
	ans -= board[0][N+1];
	ans -= board[N+1][0];
	ans -= board[N+1][N+1];

	printf("%d\n", ans);
	return 0;
}