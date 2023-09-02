#include <iostream>
#include <algorithm>
using namespace std;
int input[1000001];
long long input_sum[1000001];
int same_num[1001];
long long make_len(long long same){
	long long ret = 0;
	if (same >= 2){
		ret = (same * (same -1)) / 2;
	}
	return ret;
}

int main(){
	int n,m;
	cin >> n>> m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ret = 0;
	for (int i=1; i<=n;i++){
		cin >> input[i];
		input_sum[i] = (input[i] + input_sum[i - 1]);
		same_num[input_sum[i] % m]++;
	}
	same_num[0]++;
	for (int i=0;i <= m; i++){
		ret += make_len(same_num[i]);
	}
	cout << ret<< "\n";
}