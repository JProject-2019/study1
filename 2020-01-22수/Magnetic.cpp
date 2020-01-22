//[SW Expert] Magnetic

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//N = 1   S = 2
int main() {
	for (int test_case{ 1 }; test_case <= 10; test_case++) {
		int N;
		cin >> N;

		vector<int> status(100, 0);
		vector<vector<int>> mag(100, status);

		int count{ 0 };
		for (int r{ 0 }; r < 100; r++) {
			for (int c{ 0 }; c < 100; c++) {
				int m;
				cin >> m;

				if (m == 1) {
					status[c] = 1;
				}
				else if (m == 2) {
					if (status[c] == 1) {
						count++;
						status[c] = 2;
					}
				}
				else continue;
			}
		}


		cout << "#" << test_case << " " << count << "\n";
	}

	//system("pause");
	return 0;
}