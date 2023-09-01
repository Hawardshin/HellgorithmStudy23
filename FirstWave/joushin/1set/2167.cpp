#include <iostream>
using namespace std;
long long input[301][301];
long long sum_input[301][301];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j = 1; j <= m; j++){
			cin >> input[i][j];
			sum_input[i][j] = sum_input[i][j - 1] + input[i][j];
		}
	}
	int cnt;
	cin >> cnt;
	int x1,y1,x2,y2;
	for(int i=0;i < cnt;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		int ret = 0;
		for(int j = x1; j <= x2; j++){
			ret +=  sum_input[j][y2] - sum_input[j][y1 - 1];
		}
		cout << ret << "\n";
	}

}