//[���� 9465] ��ƼĿ

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case{ 0 }; test_case < T; test_case++) {
		int N;
		cin >> N;

		int sum{ 0 };		

		vector<vector<int>> sticker(2, vector<int>(N, 0));
		for (int n{ 0 }; n < N; n++) {
			cin >> sticker[0][n];
		}
		for (int n{ 0 }; n < N; n++) {
			cin >> sticker[1][n];
		}

		if (N == 1) {
			sum = max(sticker[0][0], sticker[1][0]);
			cout << sum << "\n";
		}
		else if (N == 2) {
			sum = max(sticker[0][0] + sticker[1][1], sticker[0][1] + sticker[1][0]);
			cout << sum << "\n";
		}
		else if (N == 3) {
			vector<int> temp = { sticker[0][0] + sticker[1][1] + sticker[0][2],
				sticker[0][0] + sticker[1][2],
				sticker[1][0] + sticker[0][1] + sticker[1][2],
				sticker[1][0] + sticker[0][2] };

			sort(temp.begin(), temp.end());
			sum = temp.back();
			cout << sum << "\n";
		}
		else { //4 �̻�
			vector<vector<int>> dp(3);

			//N=2
			dp[0].push_back(sticker[0][0] + sticker[1][1]); //�Ʒ����� ��
			dp[0].push_back(sticker[0][1] + sticker[1][0]); //������ ��
			
			//N=3
			dp[1].push_back(max(sticker[0][0] + sticker[1][2], sticker[1][0] + sticker[0][1] + sticker[1][2])); //�Ʒ����� ��
			dp[1].push_back(max(sticker[1][0] + sticker[0][2], sticker[0][0] + sticker[1][1] + sticker[0][2])); //������ ��

			int num{ 4 };
			while (num <= N) {

				//sticker [1][num]���� ��(�Ʒ�)
				dp[2].push_back(max(
					sticker[1][num - 1] + dp[0][1],	sticker[1][num - 1] + dp[1][1]));

				//sticker [0][num]���� ��(��)
				dp[2].push_back(max(
					sticker[0][num - 1] + dp[0][0],	sticker[0][num - 1] + dp[1][0]));
			

				num++;
				dp[0] = dp[1];
				dp[1] = dp[2];
				dp[2].clear();
			}

			sum = max(dp[1][0], dp[1][1]);
			cout << sum << "\n"; 
		}		
	}
	system("pause");
	return 0;
}