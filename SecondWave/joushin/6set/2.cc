#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int DP[1001];
int N;
int max_s = 1;

int calcDp(int i){
	int ret =1;
	for(int j=0;j<i;j++){
		if (arr[j] < arr[i])
			ret = max(ret,DP[j] + 1);
	}
	max_s = max(ret, max_s);
	return ret;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> arr[i];
	DP[0] = 1;
	for(int i=1;i<N;i++){
		DP[i] = calcDp(i);
	}
	cout << max_s << "\n";
}