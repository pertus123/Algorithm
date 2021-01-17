#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, T, ans = 999999;
vector<string> S;
string s;

int cal(string a, string b) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) sum++;
	}
	return sum;
}

int main() {
	cin >> T;

	while (T--) {
		ans = 999999;;
		cin >> N;
		S.clear();

		for (int i = 0; i < N; i++) {
			cin >> s;
			S.push_back(s);
		}

		if (N >= 33) {
			cout << "0" << endl;
			continue;
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int oSum = cal(S[i], S[j]);
				if (oSum >= ans) continue;

				for (int k = j + 1; k < N; k++) {
					int tSum = cal(S[i], S[k]);
					int ttSum = cal(S[j], S[k]);
					if (oSum + tSum + ttSum < ans) {
						ans = oSum + tSum + ttSum;
					}
				}
			}
		}

		
		cout << ans  << endl;
	}

	return 0;
}