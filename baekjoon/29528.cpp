#include <iostream>
#include <string>
using namespace std;
int N, sw;
string S[101];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> S[i];
    
	char a = S[0][0];

	for (int i = 1; i < N; i++) {
		if (S[i][0] != a) {
			sw = 1;
			break;
		}
	}

	if (sw == 1) cout << "0"<<endl;
    else cout << "1" << endl;
	return 0;
}