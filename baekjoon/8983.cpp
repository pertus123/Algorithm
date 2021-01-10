#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, L, ans;
vector<int> board;

int main() {

	scanf("%d %d %d", &M, &N, &L);
	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		board.push_back(x);
	}

	sort(board.begin(), board.end());

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		if (y > L) continue;

		int up = x + L - y;
		int down = x + y - L;

		int low = 0;
		int high = board.size() - 1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (board[mid] <= up && board[mid] >= down) {
				ans++;
				break;
			}
			else if (board[mid] > up) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}

		}
	}

	printf("%d\n", ans);


	return 0;
}