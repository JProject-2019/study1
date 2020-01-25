//[백준 1463] 1로 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << "0";
		return 0;
	};

	int count{ 0 };
	vector<int> temp = { N };
	while (true) {
		count++;

		vector<int> temp2;
		for (auto a : temp) {
			if (a % 3 == 0 && a / 3 >= 1) temp2.push_back(a / 3);
			if (a % 2 == 0 && a / 2 >= 1) temp2.push_back(a / 2);
			if (a - 1 >= 1)temp2.push_back(a - 1);
		}

		sort(temp2.begin(), temp2.end());
		temp2.erase(unique(temp2.begin(), temp2.end()), temp2.end());

		if (find(temp2.begin(), temp2.end(), 1) != temp2.end()) break;
		temp = temp2;
	}

	cout << count;

	//system("pause");
	return 0;
}