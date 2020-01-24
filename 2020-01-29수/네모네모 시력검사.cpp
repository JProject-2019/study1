//[���� 18242] �׸�׸� �÷°˻�

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;

	getchar();

	//�������Է�
	vector<vector<int>> map(N, vector<int>(M, 0));
	for (int n{ 0 }; n < N; n++) {
		for (int m{ 0 }; m < M; m++) {
			map[n][m] = getchar();
		}
		getchar();
	}

	//���� �� ������ ã��
	vector<int> point;
	for (int n{ 0 }; n < N; n++) {
		bool go{ true };
		for (int m{ 0 }; m < M; m++) {
			if (map[n][m] == '#') {
				point.push_back(n);
				point.push_back(m);
				go = false;
				break;
			}
		}
		if (go == false) break;
	}

	vector<string> answer = { "UP", "RIGHT", "DOWN", "LEFT" };

	vector<vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} }; // ������, �Ʒ�, ����, ��
	int direction{ 0 };

	while (true) {
		int x = point[0] + dir[direction][0];
		int y = point[1] + dir[direction][1];


		if (x >= 0 && x < N && y >= 0 && y < M) {
			point[0] = x;
			point[1] = y;
			
			if (map[x][y] == '.') {
				int a = x + dir[direction][0];
				int b = y + dir[direction][1];

				if (a >= 0 && a < N && b >= 0 && b < M) {

					if (map[a][b] == '#') {
						cout << answer[direction];
						break;
					}
					else {
						point[0] -= dir[direction][0];
						point[1] -= dir[direction][1];
						direction++;
					}
				}
				else {
					point[0] -= dir[direction][0];
					point[1] -= dir[direction][1];
					direction++;
				}
			}			
		}
		else {
			direction++;
		}
	}

	//system("pause");
	return 0;
}