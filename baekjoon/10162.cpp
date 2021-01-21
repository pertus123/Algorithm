#include <stdio.h>

int main() {

	int arr[3] = { 0 };
	int n;

	scanf("%d", &n);

	if (n % 10 != 0) printf("-1");

	else {
		while (n != 0) {
			if (n - 300 >= 0) {
				n -= 300;
				arr[0]++;
			}
			else if (n - 60 >= 0) {
				n -= 60;
				arr[1]++;
			}
			else{
				n -= 10;
				arr[2]++;
			}
		}

		printf("%d %d %d", arr[0], arr[1], arr[2]);
	}

	return 0;
}