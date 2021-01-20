#include <stdio.h>
int q1, q2, q3, q4, axis;
void func(int n, int m) {
	if (n>0 && m>0) q1++;
	else if (n < 0 && m>0) q2++;
	else if (n < 0 && m < 0) q3++;
	else if (n > 0 && m < 0) q4++;
	else axis++;
}

int main() {

	int t;
	int n, m;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		func(n, m);
	}

	printf("Q1: %d\n", q1);
	printf("Q2: %d\n", q2);
	printf("Q3: %d\n", q3);
	printf("Q4: %d\n", q4);
	printf("AXIS: %d\n", axis);

	return 0;
}