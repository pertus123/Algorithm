#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> crane;
vector<int> box;
int N, M, ans;

void input() {
	int tmp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		crane.push_back(tmp);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		box.push_back(tmp);
	}
	sort(crane.begin(), crane.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());
}

void cal() {
	int nSize = crane.size();
	int point = 0;
	int i;

	for (i = 0; i < nSize; i++) {
		int mSize = box.size();
		int sw = 0;
		for (int j = point; j < mSize; j++) {
			if (crane[i] >= box[j]) {
				box.erase(box.begin() + j);
				point = j;
				sw = 1;
				break;
			}
		}
		if (sw == 0) {
			break;
		}
	}

	if (i != nSize) {
		crane.erase(crane.begin() + i, crane.end());
	}
}

int main() {
	input();

	if (crane[0] < box[0]) {
		printf("-1\n");
	}
	else {
		while (1) {
			ans++;
			cal();

			if (box.size() == 0) break;
		}
		printf("%d\n", ans);
	}

	return 0;
}