/* 
 * @author DongsikChoi
 * BOJ 16954 움직이는 미로 탈출
 * 문제의 핵심은 오른쪽 끝으로 갈 수 있는 것이 아니라 board에 '#'이 없어지는 것을 찾는 것.
 * 크기는 8*8이므로, 9방향(제자리 포함)으로 움직이면서 벽돌을 내린다. 8번 내렸을 때 살아있다면 탈출 가능. 
 */

#include <iostream>
using namespace std;
int ans;
char board[8][8];
int dir[][2] = { {0,0},  {0,1}, {0,-1}, {1,0}, {1,-1}, {1,1}, {-1,0}, {-1,1}, {-1,-1} };

void down() {
	for (int i = 7; i >=1; i--) 
		for (int j = 0; j < 8; j++) 
			board[i][j] = board[i-1][j];

	for (int j = 0; j < 8; j++)
		board[0][j] = '.';
}

void dfs(int cnt, int x, int y) {
	if (ans == 1) return;
	if (cnt == 8) {
		ans = 1;
		return;
	}

	down();
	char tempBoard[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			tempBoard[i][j] = board[i][j];

	if (board[x][y] == '#') return;

	for (int i = 0; i <= 8; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
		if (board[nx][ny] == '#') continue;
		board[x][y] = '.';
		board[nx][ny] = 'S';
		dfs(cnt + 1, nx, ny);
		if (ans == 1) return;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) board[i][j] = tempBoard[i][j];
	}
}

int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf(" %c", &board[i][j]);
	char tempBoard[8][8];

	if (board[7][0] == '#') printf("0\n");

	else {
		board[7][0] = 'S';
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				tempBoard[i][j] = board[i][j];


		for (int i = 0; i <= 8; i++) {
			int nx = 7 + dir[i][0];
			int ny = 0 + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			if (board[nx][ny] == '#') continue;
			board[7][0] = '.';
			board[nx][ny] = 'S';
			dfs(1, nx, ny);
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					board[i][j] = tempBoard[i][j];
		}
		printf("%d\n", ans);
	}
	return 0;
}