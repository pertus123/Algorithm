#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int n, h, w, m, k;
int arr[501][501] = { {0,}, }; /* 험준도 */
int map[501][501] = { {0,}, }; /* 맵에 존재하는 유닛 번호표시(벡터의 인덱스) */
int visited[501][501] = { {0, }, };
int slope[10];
int dy[4] = { 0 ,0 ,1 ,-1 };
int dx[4] = { 1, -1, 0, 0 };
int sw = 0;

class Unit {
public:
	int m, t, y, x; // 속 진
};
vector<Unit> v;

bool move(int& u, int& _y, int& _x) {
	if (map[_y][_x]) return false; /* 도착지점에 유닛이 있음 */
	if (slope[arr[_y][_x]] == -1) return false; /* 갈 수 없는 지형 */
	int y = v[u].y, x = v[u].x;
	int s = v[u].m, t = v[u].t;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(s, make_pair(y, x)));
	visited[y][x] = s;
	int ny, nx, ns;
	bool flag;
	while (!pq.empty()) {
		s = pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();
		if (s < visited[y][x]) continue;
		flag = true;
		/* 현 위치에서 주변에 적이 있다면 정지 */
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
			if (map[ny][nx] && v[map[ny][nx]].t != t) { /* 유닛이 존재하고 그 유닛이 적일 경우 == 교전 */
	//			if (v[map[ny][nx]].t == 3) continue;
				if (sw == 1) continue;
				flag = false;
				break;
			}
		}
		if (!flag) continue;


		/* 다음칸으로 이동가능한지 판별 */
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) continue; /* 범위체크 */
			if (map[ny][nx] && v[map[ny][nx]].t != t) continue; //
			ns = s - slope[arr[ny][nx]]; /* 소모한 스태미너 */
			if (slope[arr[ny][nx]] == -1 || ns < 0) continue; /* 갈 수 없는 지형이거나 스태미너 초과 */
			if (ny == _y && nx == _x) return true; /* 목표도착 */
			if (ns <= visited[ny][nx]) continue;
			pq.push(make_pair(ns, make_pair(ny, nx)));
			visited[ny][nx] = ns;
		}
		sw = 0;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	cin >> n >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		cin >> slope[i];

	v.push_back({ 0, 0, 0, 0 }); /* 1번 index부터 시작하기위해 넣어줌 */
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c >> d;
		v.push_back({ a, b, c, d });
		map[c][d] = i; /* 맵에 유닛 표시 */
	}
	cin >> k;
	for (int ki = 0; ki < k; ki++) {
		cin >> a >> b >> c;
		memset(visited, 0, sizeof(visited));
		
		int fx = v[a].x;
		int fy = v[a].y;
		int tt = v[a].t;
		sw = 0;
		int tmp = 0;
		int tx, ty;
		for (int i = 0; i < 4; i++) {
			int ny = fy + dy[i];
			int nx = fx + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
			if (map[ny][nx] != 0 && v[map[ny][nx]].t != tt) {
				sw = 1;
				//v[map[ny][nx]].t = 3;
			}

		}

		if (move(a, b, c)) { /* 명령 수행 */
			map[b][c] = a;
			map[v[a].y][v[a].x] = 0;
			v[a].y = b;
			v[a].x = c;
		}

	/*	if (sw == 1) {
			for (int i = 0; i < 4; i++) {
				int ny = fy + dy[i];
				int nx = fx + dx[i];
				if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
				if (map[ny][nx] != 0 && v[map[ny][nx]].t != tt) {
					v[map[ny][nx]].t = 1- tt;
				}
			}
		}*/

	}
	for (int i = 1; i <= m; i++)
		cout << v[i].y << " " << v[i].x << '\n';
	return 0;
}