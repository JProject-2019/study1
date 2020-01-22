//[���α׷��ӽ�] �ܾȯ

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0; //���ѷ��� ����

	set<string> history;
	history.insert(begin);

	vector<string> temp;
	temp.push_back(begin);

	vector<string> temp2;

	while (true) {
		answer++;

		for (auto t : temp) {

			for (int i{ 0 }; i < words.size(); i++) {

				//�ٸ� ���� ��, �ٸ� �ε��� ��ġ
				int count{ 0 };
				int index;
				for (int j{ 0 }; j < t.size(); j++) {
					if (t[j] != words[i][j]) {
						count++;
						index = j;
					}
				}

				if (count == 1) {
					string tt = t;
					tt[index] = words[i][index];
					if (history.count(tt) == 0) {
						temp2.push_back(tt);
						history.insert(tt);
					}
				}
			}
		}
		//temp2 ����� 0�̶��, �� ���� �ٲ� �� �ִ� ���ڰ� ���ٸ� ����
		if (temp2.size() == 0) return 0; 
		//temp2�� target�� �����Ѵٸ� ����
		else if (find(temp2.begin(), temp2.end(), target) != temp2.end()) {
			return answer;
		}
		else temp = temp2;

		temp2.clear();
	}
}



int main() {
	vector<string> s = { "hot", "dot", "dog", "lot", "log", "cog" };
	cout << solution("hit", "cog", s);
	system("pause");
	return 0;
}