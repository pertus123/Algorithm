#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int R, C;
vector<string> sArr;
char board[21][21];

void input() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			scanf(" %c", &board[i][j]);
}

void hori() {
	for (int i = 0; i < R; i++) {
		string s;
		for (int j = 0; j < C; j++) {
			if (board[i][j] != '#') {
				s += board[i][j];
			}
			else {
				if(s.size() > 1) sArr.push_back(s);
				s = "";
			}
		}
		if (s.size() > 1) sArr.push_back(s);
	}
}

void ver() {
		for (int j = 0; j < C; j++) {
			string s;
			for (int i = 0; i < R; i++) {
			if (board[i][j] != '#') {
				s += board[i][j];
			}
			else {
				if (s.size() > 1) sArr.push_back(s);
				s = "";
			}
		}
		if (s.size() > 1) sArr.push_back(s);
	}
}

int main() {
	input();
	hori();
	ver();

	sort(sArr.begin(), sArr.end());
	cout << sArr[0] << endl;

	return 0;
}