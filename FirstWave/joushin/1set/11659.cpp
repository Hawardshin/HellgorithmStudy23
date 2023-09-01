# include <iostream>

using namespace std;
int arr[100001];
int sum[100001];
int main(){
	int N,M;
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		if (i == 0)
			sum[0] = arr[0];
		else 
			sum[i] = sum[i - 1] + arr[i];
	}
	int r,l;
	for (int i = 0; i < M; i++){
		cin >> r >> l;
		if (r == 1)
			cout << sum[l - 1] << "\n";
		else 
			cout << sum[l - 1] -  sum[r - 2] << "\n"; 
	}
}