#include <iostream>
#include <vector>
using namespace std;
int map[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	int n;
	int y, x, d, g;
	scanf("%d", &n);

	for (int t = 0; t < n; t++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector<int> dir;
		dir.push_back(d);

		for (int k = 1; k <= g; k++)
			for (int j = dir.size() - 1; j >= 0; j--)
				dir.push_back((dir[j] + 1) % 4);

		map[y][x] = 1;
		for (int i = 0; i < dir.size(); i++) {
			x = x + dx[dir[i]];
			y = y + dy[dir[i]];
			map[y][x]++;
		}
	}


	int cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) cnt++;

	printf("%d\n", cnt);

	return 0;
}