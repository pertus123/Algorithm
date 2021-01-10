#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<long long int> pq;

int main() {
	scanf("%d", &N);
	long long int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &tmp);
		pq.push(-tmp);
	}

	long long int ans = 0;

	while (pq.size() > 1) {
		long long int x = -pq.top();
		pq.pop();
		long long int y = -pq.top();
		pq.pop();
		ans += (x + y);
		pq.push(-(x + y));
	}

	printf("%lld\n", ans);

	return 0;
}