// 보고푼 문제2
#include <iostream>
#include <vectoir>

using namespace std;

int n, l;
int arr[101][101];
int arr2[101][101];
int ret;

void solve(int arr[101][101]) {
	for (int i = 1; i <= n; i++) {
		int height = 0, cnt = 0;

		vector<pair<int, int> > vector;
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				height = arr[i][j];
				cnt = 1;
				continue;
			}
			if (arr[i][j] == height)
				cnt++;
			else {
				vector.push_back({ height, cnt });
				height = arr[i][j];
				cnt = 1;
			}
		}
		vector.push_back({ height,cnt });

		if (vector.size() == 1) {
			ret++;
			continue;
		}
		bool flag = true;

		for (int k = 0; k < vector.size() - 1; k++) {
			if (abs(vector[k].first - vector[k + 1].first) > 1) {
				flag = false;
				break;
			}

			if (vector[k].first < vector[k + 1].first) {
				if (vector[k].second < l) {
					flag = false;
					break;
				}
			}
			else {
				if (vector[k + 1].second < l) {
					flag = false;
					break;
				}
				else {
					vector[k + 1].second -= l;
				}

			}
		}
		if (flag) ret++;
	}

}

int main() {
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr2[j][i] = arr[i][j];
		}
	}
	
	solve(arr);
	solve(arr2);


	cout << ret << endl;


	return 0;

}
