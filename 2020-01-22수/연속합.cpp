//[백준 #1912] 연속합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> sumV(1);

	int num;
	cin >> num;
	sumV[0] = num;

	for (int n{ 1 }; n < N; n++) {
		int num;
		cin >> num;

		num = max(num, num + sumV[n - 1]);
		sumV.push_back(num);
	}
	
	sort(sumV.begin(), sumV.end());
	cout << sumV.back();

	system("pause");
	return 0;
}