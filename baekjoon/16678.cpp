#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int ans;
vector<int> num;

int main() {

	int N;
	scanf("%d", &N);
	int k;
	for (int i = 0; i < N; i++) {
		scanf("%d", &k);
		num.push_back(k);
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
		if (num[i] > i + 1) {
			ans += num[i] - (i + 1);
		}
		else if (num[i] < i + 1) {
			num.erase(num.begin() + i);
			i--;
		}
	}

	printf("%lld\n", ans);
	
	return 0;
}