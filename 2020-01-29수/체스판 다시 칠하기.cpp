//[백준 1018] 체스판 다시 칠하기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> board;
	for (int i{ 0 }; i < N; i++) {
		string s;
		cin >> s;

		board.push_back(s);
	}

	int count{ 64 };
	for (int n{ 0 }; n < N - 8 + 1; n++) {
		for (int m{ 0 }; m < M - 8 + 1; m++) {
			int color{ 0 };

			for (int i{ n }; i < n + 8; i++) {
				for (int j{ m }; j < m + 8; j++) {
					if (i % 2 == 0) {
						if (j % 2 == 0) {
							if (board[i][j] == 'B') color++;
						}
						else { if (board[i][j] == 'W') color++; }
					}
					else {
						if (j % 2 == 0) { if (board[i][j] == 'W') color++; }
						else { if (board[i][j] == 'B') color++; }
					}
				}
			}

			color = min(color, 64 - color);
			count = min(count, color);
		}
	}

	cout << count;

	//system("pause");
	return 0;
}