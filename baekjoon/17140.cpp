#include <iostream>
using namespace std;
int r, c, K;
int board[1010][1010], check[1010];

int main() {
	scanf("%d %d %d", &r, &c, &K);
	int maxRow = 3, maxCol = 3;
	for (int i = 1; i <= maxRow; i++)
		for (int j = 1; j <= maxCol; j++) scanf("%d", &board[i][j]);
	int t = 0; // 시간

	while (1) {
		if (board[r][c] == K) break;
		int maxCnt = 0;

		if (maxRow >= maxCol) {																					//1번
			for (int i = 1; i <= maxRow; i++) {
				for (int j = 1; j <= maxCol; j++) check[board[i][j]]++;// 각 숫자들의 개수 체크

				int cnt = 1;
				for (int q = 1; q <= 100; q++) { // A 에 배치.
					for (int k = 1; k <= 100; k++) {
						if (check[k] == q) {
							board[i][cnt++] = k; // 2가 1개 에서 2
							board[i][cnt++] = q; // k의 개수
							check[k] = 0;
						}
					}
				} // 한 줄 완료.
                
				check[0] = 0;
				if (maxCnt < cnt) { maxCnt = cnt; }
				for (int k = cnt; k <= 100; k++) board[i][k] = 0;//	for (int k = cnt; k <= maxCnt; k++) board[i][k] = 0;
			}
			t++; 

			if (maxCol < maxCnt) {
				maxCol = maxCnt;
				if (maxCol > 100) maxCol = 100;
			}
		}
		if (board[r][c] == K || t > 100) {
			if(t > 100) t = -1;
			break;
		}
		maxCnt = 0;

		//part2
		if (maxRow < maxCol) {																						// part 2
			for (int i = 1; i <= maxCol; i++) {
				for (int j = 1; j <= maxRow; j++) check[board[j][i]]++;

				int cnt = 1;
				for (int q = 1; q <= 100; q++) { // A 에 배치.
					for (int k = 1; k <= 100; k++) {
						if (check[k] == q) {
							board[cnt++][i] = k; // 2가 1개 에서 2
							board[cnt++][i] = q; // k의 개수
							check[k] = 0;
						}
					}
				}
				check[0] = 0;
				if (maxCnt < cnt) maxCnt = cnt;
				for (int k = cnt; k <= 100; k++) board[k][i] = 0;
			}

			t++;
			if (maxRow < maxCnt) {
				maxRow = maxCnt;
				if (maxRow > 100) maxRow = 100;
			}
		}

		if (board[r][c] == K || t > 100) {
			if(t >100) t = -1;
			break;
		}
		maxCnt = 0;
	}

	printf("%d\n", t);
	return 0;
}