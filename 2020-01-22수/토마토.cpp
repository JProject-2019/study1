//[백준 7569] 토마토

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <set>

using namespace std;


//익은토마토=1 익지않은토마토=0 비어있는칸=-1
int main() {

	//가로, 세로, 높이
	int X, Y, H;
	cin >> X >> Y >> H;


	//토마토 상태 입력
	vector<int> width(X);
	vector<vector<int>> length(Y, width);

	vector<tuple<int,int,int>> ls; //안익은 토마토
	vector<tuple<int, int, int>> ripe;//방금 익은 토마토

	vector<vector<vector<int>>> tomato(H,length);

	for (int h{ 0 }; h < H; h++) {
		for (int y{ 0 }; y < Y; y++) {
			for (int x{ 0 }; x < X; x++) {
				cin >> tomato[h][y][x];
				if (tomato[h][y][x] == 0) ls.push_back(make_tuple(h, y, x));
				if (tomato[h][y][x] == 1) ripe.push_back(make_tuple(h, y, x));
			}
		}
	}

	//안익은 토마토가 없을경우 종료
	if (ls.size() == 0) { 
		cout << "0"; 
		//system("pause");
		return 0; 
	}

	//방향이동
	vector<tuple<int, int, int>> direction;
	direction.push_back(make_tuple(-1, 0, 0)); // 높이 증가
	direction.push_back(make_tuple(1, 0, 0)); // 높이 감소
	direction.push_back(make_tuple(0, -1, 0)); // 상
	direction.push_back(make_tuple(0, 1, 0)); // 하
	direction.push_back(make_tuple(0, 0, -1)); // 좌
	direction.push_back(make_tuple(0, 0, 1)); // 우


	//토마토가 모두 익을 수 없는 경우 검사
	for (auto a : ls) {
		int count{ 0 };
		int count2{ 0 };

		for (auto dir : direction) {
			int p = get<0>(a) + get<0>(dir); //높이
			int q = get<1>(a) + get<1>(dir); //세로
			int r = get<2>(a) + get<2>(dir); //가로

			if (p >= 0 && p < H && q >= 0 && q < Y && r >= 0 && r < X) {
				if (tomato[p][q][r] == -1) count++;
			}
			else count2++;
		}
		if (count == 6 - count2) {
			cout << "-1";
			//system("pause");
			return 0;
		}		
	}

	//토마토가 다 익을 때까지 걸리는 날 계산
	int days{ 0 };
	unsigned int left{ ls.size() }; //익어야할 토마토 수

	while (left > 0) {
		days++;

		vector<tuple<int, int, int>> temp;//방금 익은 토마토

		for (auto a : ripe) {
			for (auto dir : direction) {
				int p = get<0>(a) + get<0>(dir); //높이
				int q = get<1>(a) + get<1>(dir); //세로
				int r = get<2>(a) + get<2>(dir); //가로

				if (p >= 0 && p < H && q >= 0 && q < Y && r >= 0 && r < X) {
					if (tomato[p][q][r] == 0) {
						tomato[p][q][r] = 1;
						left--;
						temp.push_back(make_tuple(p, q, r));
					}
				}
			}
		}

		//토마토를 더 익힐 수 없는 경우
		if (left != 0 && temp.size() == 0) {
			cout << "-1";
			//system("pause");
			return 0;
		}

		ripe = temp;
	}
	cout << days;
	//system("pause");
	return 0;
}