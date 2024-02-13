#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
long long dp[101];

void printMax(){
	if (N %2 != 0){
		cout << 7;
		N-=3;
	}
	for(int i=0;i<N/2;i++) cout << 1;
	cout << "\n";
}

int main(){
	int x ;
	cin >> x;
	int min_num[8] = { 0,0,1,7,4,2,0,8 };
	memset(dp, 0x7f , sizeof(dp));
	dp[1] = 9; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;
	for (int i= 8; i<=100 ; ++i) 
		for (int j = 2; j<=7 ; ++j) 
			dp[i] = min(dp[i], dp[i-j]*10 + min_num[j]);
	for(int i=0;i<x;i++){
		cin >> N;
		cout << dp[N] << ' ';
		printMax();
	}
}