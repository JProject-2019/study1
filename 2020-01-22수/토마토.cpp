//[���� 7569] �丶��

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <set>

using namespace std;


//�����丶��=1 ���������丶��=0 ����ִ�ĭ=-1
int main() {

	//����, ����, ����
	int X, Y, H;
	cin >> X >> Y >> H;


	//�丶�� ���� �Է�
	vector<int> width(X);
	vector<vector<int>> length(Y, width);

	vector<tuple<int,int,int>> ls; //������ �丶��
	vector<tuple<int, int, int>> ripe;//��� ���� �丶��

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

	//������ �丶�䰡 ������� ����
	if (ls.size() == 0) { 
		cout << "0"; 
		//system("pause");
		return 0; 
	}

	//�����̵�
	vector<tuple<int, int, int>> direction;
	direction.push_back(make_tuple(-1, 0, 0)); // ���� ����
	direction.push_back(make_tuple(1, 0, 0)); // ���� ����
	direction.push_back(make_tuple(0, -1, 0)); // ��
	direction.push_back(make_tuple(0, 1, 0)); // ��
	direction.push_back(make_tuple(0, 0, -1)); // ��
	direction.push_back(make_tuple(0, 0, 1)); // ��


	//�丶�䰡 ��� ���� �� ���� ��� �˻�
	for (auto a : ls) {
		int count{ 0 };
		int count2{ 0 };

		for (auto dir : direction) {
			int p = get<0>(a) + get<0>(dir); //����
			int q = get<1>(a) + get<1>(dir); //����
			int r = get<2>(a) + get<2>(dir); //����

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

	//�丶�䰡 �� ���� ������ �ɸ��� �� ���
	int days{ 0 };
	unsigned int left{ ls.size() }; //�;���� �丶�� ��

	while (left > 0) {
		days++;

		vector<tuple<int, int, int>> temp;//��� ���� �丶��

		for (auto a : ripe) {
			for (auto dir : direction) {
				int p = get<0>(a) + get<0>(dir); //����
				int q = get<1>(a) + get<1>(dir); //����
				int r = get<2>(a) + get<2>(dir); //����

				if (p >= 0 && p < H && q >= 0 && q < Y && r >= 0 && r < X) {
					if (tomato[p][q][r] == 0) {
						tomato[p][q][r] = 1;
						left--;
						temp.push_back(make_tuple(p, q, r));
					}
				}
			}
		}

		//�丶�並 �� ���� �� ���� ���
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