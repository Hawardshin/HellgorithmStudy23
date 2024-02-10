#include <iostream>

using namespace std;

int N;
int input[101];

//계산을 dfs로 하긴 하되, 이미 이전에 해당 위치에 도달한적 있다면..?

/*
1 1 1 1 = ?
굳이 인덱스로 하지 말자
오는 방향은 달랐지만 뒤의 진행은 동일
1+1-1+1
1-1+1+1
dp[X인덱스 숫자][해당 값] = 갯수 
dp[2][1] = 2;
dp[3][1] = ????
dp[x번째 숫자][해당 값] = dp[x-1번째 숫자][해당값-input[x]] + dp[x-1][해당값+input[x]];
dp[0][0]=0;
dp[0][1]=1;
dp[0][2]=0;...
dp[0][20]=0;


dp[1][0]=dp[0][0-1(두번째 1)]+dp[0][0+1(두번째1)] = 0+1;
dp[1][1]=dp[0][1-1(두번째 1)]+dp[0][1+1] = 0+0;
dp[1][2]=dp[0][2-1]+dp[0][2+1] = 1+0;
dp...

dp[2][0] = dp[0][0-1]+ dp[0][1+1] = 0
*/


long long dp[101][21];
//[몇번째][수] = 갯수

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >>input[i];
	}
	dp[1][input[1]] = 1;
	for(int idx=2;idx<N;idx++){
		for(int num=0;num<=20;num++){
			long long a=0,b=0;
			if (num-input[idx] >= 0)
				a = dp[idx-1][num-input[idx]];
			if (num+input[idx] <= 20)
				b = dp[idx-1][num+input[idx]];
			dp[idx][num] = a + b;
			// cout << idx <<"번 째"<< num << "이: " << dp[idx][num]<< "\n";
		}
		// cout << "----------------------------\n";
	}

	cout << dp[N-1][input[N]] << "\n";
}