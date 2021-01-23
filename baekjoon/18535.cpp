#include <iostream>
using namespace std;

int N, soldier[2000], memo[2000];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> soldier[i];
    
    int answer = N;
	// O(n^2) LIS 해결법: 최대 내림차순 수열 길이 찾기
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j) {
            if (soldier[j] > soldier[i])
                memo[i] = max(memo[i], memo[j] + 1);
            answer = min(answer, N - memo[i] - 1);
        }
    if (answer == N) cout << "0\n";
    else cout << answer << '\n';
}