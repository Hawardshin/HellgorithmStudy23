#include <iostream>
using namespace std;
int N, M;
int input[1025][1025];
int line_sum[1025][1025];
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			 cin >> input[i][j];
			if (j == 0)
				line_sum[i][j] = input[i][j];
			else
				line_sum[i][j] = line_sum[i][j - 1] + input[i][j];
		}
	}
	int x1, x2, y1,y2;
	for (int i = 0; i < M; i++){
		cin >> x1 >>y1>> x2 >> y2;
		int ret = 0;
		for (int j = x1 - 1; j < x2; j++){
			if (y1 > 1)
				 ret += line_sum[j][y2 - 1] - line_sum[j][y1 - 2];
			else
				ret += line_sum[j][y2 - 1];
		}
		cout << ret << "\n";
	}
}