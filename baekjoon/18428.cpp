#include <iostream>
#include <vector>
using namespace std;
int board[6][6];
vector<pair<int, int>> S;
int N, sw;
int dir[][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void input() {
	char c;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &c);
			if (c == 'T') {
				board[i][j] = 2;
				S.push_back({ i,j });
			}
			else if (c == 'S') {
				board[i][j] = 1;
			}
		}
	}
}

void eval() {
	int tmp = 0;
	int sSize = S.size();
	for (int i = 0; i < sSize; i++) {
		for (int j = 0; j < 4; j++) {
			int x = S[i].first;
			int y = S[i].second;

			while (x + dir[j][0] < N && x + dir[j][0] >= 0 && y + dir[j][1] >= 0 && y + dir[j][1] < N) {
				x += dir[j][0];
				y += dir[j][1];
				if (board[x][y] == -1) {
					break;
				}
				if (board[x][y] == 1) {
					return;
				}
			}
		}
	}

	sw = 1;
}

void dfs(int x, int y, int cnt) {
	if (sw)return;
	if (cnt == 2) {
		eval();
		return;
	}

	int j = y + 1;
	for (int i = x; i < N; i++, j = 0) {
		for (j; j < N; j++) {
			if (board[i][j] == 0) {
				board[i][j] = -1;
				dfs(i, j, cnt + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	input();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				board[i][j] = -1;
				dfs(i, j, 0);
				board[i][j] = 0;
			}
		}
	}

	if (sw || S.size() == 0)printf("YES\n");
	else printf("NO\n");

	return 0;
}