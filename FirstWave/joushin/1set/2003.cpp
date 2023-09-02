#include <iostream>
using namespace std;
int input[10001];
int sum_input[10001];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	int start_idx = -1;
	for (int i = 0; i < n; i++){
		cin >>input[i];
		if (i != 0)
			sum_input[i] = sum_input[i - 1] + input[i];
		else 
			sum_input[i] = input[i];
		if (sum_input[i] >= m && start_idx == -1)
			start_idx = i;
	}
	int ret = 0;
	if (start_idx == -1){
		cout << ret <<"\n";
		return (0);
	}
	for (int i = start_idx; i < n; i++){
		int cnt = sum_input[i];
		for (int j = 0; cnt >  m ; j++){
			cnt = sum_input[i] - sum_input[j];
		}
		if (cnt == m)
			ret++;
	}
	cout << ret << "\n";
}