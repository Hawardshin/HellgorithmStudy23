#include <iostream>
#define studentNum 21
using namespace std;
int N;
int inputHp[studentNum];
int inputHappy[studentNum];
int ret_max = 0;
int dp[21][101];//[현재까지 만난 사람의 수][인사를 하며 지금까지 잃은 체력] = 지금까지 얻은 기쁨의 최댓값
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++) cin >> inputHp[i];
	for(int i=1;i<=N;i++) cin >> inputHappy[i];
	for(int i=1;i <= N;i++){
		for(int j=0;j<=100;j++){
			if (j + inputHp[i] < 100)
			 dp[i][j] = max(dp[i-1][j], dp[i-1][j+inputHp[i]] + inputHappy[i]); 
			else 
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if (dp[i][j] >ret_max ) ret_max = dp[i][j];
		}
	}
	cout << ret_max << "\n";
}