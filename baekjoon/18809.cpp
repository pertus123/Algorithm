#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int board[51][51], tmpBoard[51][51];
int dir[][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int G, R, N, M, ddangCnt, ans;
vector<pair<int, int>> ddang;
int d[1001];

void bfs() {
	memcpy(tmpBoard, board, sizeof(board));

	int cnt = 0;
	queue<pair<int, int>> oneQ, twoQ;

	for (int i = 0; i < ddangCnt; i++) {
		if (d[i] == 1) {
			tmpBoard[ddang[i].first][ddang[i].second] = 4;
			oneQ.push({ ddang[i].first, ddang[i].second });
		}
		else if (d[i] == 2) {
			tmpBoard[ddang[i].first][ddang[i].second] = 2;
			twoQ.push({ ddang[i].first, ddang[i].second });
		}
	}

	pair<int, int> a;
	while (!(oneQ.empty() || twoQ.empty())) {
		int oneSize = oneQ.size();
		int twoSize = twoQ.size();
		for (int i = 0; i < oneSize; i++) {
			a = oneQ.front();
			int x = a.first;
			int y = a.second;
			oneQ.pop();
			if (tmpBoard[x][y] == 1) tmpBoard[x][y] = 4;
			if (tmpBoard[x][y] != 4) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (tmpBoard[nx][ny] != 0) continue;
				tmpBoard[nx][ny] = 1;
				oneQ.push({ nx,ny });
			}
		}

		for (int i = 0; i < twoSize; i++) {
			a = twoQ.front();
			int x = a.first;
			int y = a.second;
			twoQ.pop();
			if (tmpBoard[x][y] != 2) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (tmpBoard[nx][ny] == 1) {
					tmpBoard[nx][ny] = 5;
					cnt++;
				}
				if (tmpBoard[nx][ny] != 0) continue;
				tmpBoard[nx][ny] = 2;
				twoQ.push({ nx,ny });
			}
		}
	}

	if (cnt > ans) ans = cnt;

	return;
}

void dfs(int cnt, int Gcnt, int Rcnt, int Zerocnt) {
	if (cnt == ddangCnt) {
		bfs();
		return;
	}
	if (Gcnt < G) {
		d[cnt] = 1;
		dfs(cnt + 1, Gcnt + 1, Rcnt, Zerocnt);
	}
	if (Rcnt < R) {
		d[cnt] = 2;
		dfs(cnt + 1, Gcnt, Rcnt + 1, Zerocnt);
	}
	if (Zerocnt < ddangCnt - (G + R)) {
		d[cnt] = 0;
		dfs(cnt + 1, Gcnt, Rcnt, Zerocnt + 1);
	}
}

int main() {
	int tmp;
	scanf("%d %d %d %d", &N, &M, &G, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			if (tmp == 0) {
				board[i][j] = 3;
			}
			else if (tmp == 2) {
				ddang.push_back({ i,j });
			}
		}
	}
	ddangCnt = ddang.size();

	dfs(0, 0, 0, 0);

	printf("%d\n", ans);

	return 0;
}