#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int input();
int solve_the_problem();
int output();

int a_x, a_y, a_r, b_x, b_y, b_r;
int result;
int testcase_cnt;

int main() {
	int t;

	scanf("%d", &testcase_cnt);

	for (t = 1; t <= testcase_cnt; t++) {
		input();

		solve_the_problem();

		output();

	}

	return 0;

}

int solve_the_problem() {

	double d = sqrt((double)((a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y)));
	int sum = a_r + b_r;
	int min = abs(a_r - b_r);

	if (a_x == b_x && a_y == b_y)
	{
		if (a_r == b_r)
			result = -1;
		else
			result = 0;
	}

	else
	{
		if (min < d && d < sum)
			result = 2;
		else if (d == min || d == sum)
			result = 1;
		else if (d == 0 || d > sum || d < min)
			result = 0;
	}
	return 0;
}

int input() {
	scanf("%d %d %d %d %d %d", &a_x, &a_y, &a_r, &b_x, &b_y, &b_r);

	return 0;
}

int output() {
	printf("%d\n", result);

	return 0;
}