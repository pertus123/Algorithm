#include <stdio.h>
#include <stdlib.h>

int main() {
	double arr[5];
	int test;
	double *brr;

	scanf("%d", &test);

	brr = (double *)malloc(sizeof(double)* test);

	for (int i = 0; i < test; i++) {
		scanf("%lf %lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
		brr[i] = arr[0] * 350.34 + arr[1] * 230.90 + arr[2] * 190.55 + arr[3] * 125.30 + arr[4] * 180.90;
		printf("$%.2lf\n", brr[i]);
	}

	free(brr);

	return 0;
}