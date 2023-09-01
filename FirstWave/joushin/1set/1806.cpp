#include <iostream>
using namespace std;
long long input[100001];
long long sum_input[100001];
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
	if (start_idx == -1){
		cout << 0 <<"\n";
		return (0);
	}
	int len = 100001;
	int end = 0;
	for (int start = 0; start < n; start++){
		while(end < n && sum_input[end] - sum_input[start] < m) end++;
		if (end == n){
			if (sum_input[n - 1] == m)
				len = n;
			break;
		}
			
		if (sum_input[end] - sum_input[start] >= m)
			len = min(len, end - start);
	}
if (len == 100001)
		len = 1;
	cout << len << "\n";
}