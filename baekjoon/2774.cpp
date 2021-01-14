#include <stdio.h>
#include <string.h>

int main() {

	int n, m, cnt = 0;
	char a[20];
	int b[10] = {0};

	scanf("%d ", &n);

	while (n--) {
		scanf("%s", a);
		m = strlen(a);
		for (int i = 0; i < m; i++) b[a[i] - '0']++;

		for (int i = 0; i < 10; i++) {
			if (b[i] != 0) cnt++;
			b[i] = 0;
		}
		printf("%d\n", cnt);

		cnt = 0;
	}

	return 0;
}