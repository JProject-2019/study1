//[2020카카오공채] 자물쇠와 열쇠

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>

using namespace std;

//홈:0  돌기:1
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int M = key[0].size();
	int N = lock[0].size();

	for (int i{ 0 }; i < N + M - 1; i++) {
		for (int j{ 0 }; j < N + M - 1; j++) {
			

			for (int rotate{ 0 }; rotate < 4; rotate++) {
				//key 회전 - 오른쪽으로 90도
				vector<int> l(M);
				vector<vector<int>> key2(M,l);

				for (int r{ 0 }; r < M; r++) {
					for (int c{ 0 }; c < M; c++) {
						key2[r][c] = key[M - c - 1][r];
					}
				}

				key = key2;

				vector<int> line(N + 2 * (M - 1), 3); //그냥 3
				vector<vector<int>> test(N + 2 * (M - 1), line);

				//lock 입력
				for (int n{ 0 }; n < N; n++) {
					for (int nn{ 0 }; nn < N; nn++) {
						test[M + n - 1][M + nn - 1] = lock[n][nn];
					}
				}


				//key 입력
				for (int r{ 0 }; r < M; r++) {
					for (int c{ 0 }; c < M; c++) {
						test[i+r][j+c] += key[r][c];
					}
				}

				//체크
				int count{ 0 };
				for (int n{ 0 }; n < N; n++) {
					for (int nn{ 0 }; nn < N; nn++) {
						if (test[M + n - 1][M + nn - 1] == 0) break;
						if (test[M + n - 1][M + nn - 1] == 2) break;
						if (test[M + n - 1][M + nn - 1] == 1) count++;
					}
				}

				/*
				cout << "\n\n\n" << i << " " << j << "\n";
				for (auto a : test) {
					for (auto b : a) {
						cout << setw(3) << b;
					}
					cout << "\n";
				}*/

				if (count == N*N) return true;
			}

		}
	}

	return false;
}


int main() {
	cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} },{ {1, 1, 1}, { 1, 1, 0 }, { 1, 0, 1 }});

	system("pause");
	return 0;
}


