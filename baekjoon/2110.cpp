#include <stdio.h>
#include <stdlib.h>
int a[200000];
int n, m;

int com(const void* u, const void* v) {
	if (*(int *)u > *(int *)v) return 1;
	else return -1;
}

int check(int x) {
	int cnt=1;
	int back = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] - back >= x) {
			back = a[i];
			cnt++;
		}
	}
	return cnt>=m;
}

int main() {
	int r, l, mid, ans = 0;

	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++) scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), com);

	l = 1;
	r = a[n - 1] - a[0];
	while (r >= l) {
		mid = (r + l) / 2;
		if (check(mid)) {
			if (ans <= mid) ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}