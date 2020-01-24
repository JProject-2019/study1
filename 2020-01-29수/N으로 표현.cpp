//[프로그래머스] N으로 표현

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int N, int number) {
	
	if (N == number) return 1;

	vector<vector<int>> V;
	V.push_back({}); //N 0개 짜리
	V.push_back({ N }); //N 1개 짜리

	for (int i{ 2 }; i <= 8; i++) { //N이 i개

		vector<int> temp;

		string s = "";
		for (int count{ 0 }; count < i; count++) { s.append(to_string(N)); }
		temp.push_back(atoi(s.c_str()));

		for (int first{ 1 }; first <= i / 2; first++) {
			for (auto a : V[first]) {
				for (auto b : V[i - first]) {
					temp.push_back(a + b);
					temp.push_back(a - b);
					temp.push_back(b - a);
					temp.push_back(a * b);
					if (b != 0) temp.push_back(a / b);
					if (a != 0) temp.push_back(b / a);
				}
			}
		}

		if (find(temp.begin(), temp.end(), number) != temp.end()) return i;
		
		V.push_back(temp);
	}
	return -1;
}

int main() {

	cout << solution(5, 12) << endl;
	cout << solution(2, 11) << endl;

	system("pause");
	return 0;
}