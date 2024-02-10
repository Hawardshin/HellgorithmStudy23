
#include <iostream>
#define YES 1
#define NO 2
using namespace std;

int N;
int numAr[2001];
int M;

int dp[2001][2001];

bool isPerin(int a,int b){
	if (dp[a][b] == YES)
		return true;
	else if (dp[a][b] == NO)
		return false;
	else return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin>> numAr[i];
	}
	for(int i=1;i<=N;i++){//거리가 1부터 N까지 증가
		for(int j=1;(i+j-1)<=N;j++){//시작위치가 1부터 N까지 증가
			if (i == 1)
				dp[j][j] = YES;
			else if (i == 2){
				if (numAr[j] == numAr[j+1])
					dp[j][j+1] = YES;
			}
			else {
				if (dp[j+1][j+i-2] == YES && numAr[j] == numAr[j+i-1])
					dp[j][j+i-1] = YES;
			}
			if (dp[j][j+i-1] != YES)
				dp[j][j+i-1] = NO;
		}
	}
	cin >> M;
	for(int i=0;i<M;i++){
		int fir,sec;
		cin >> fir >> sec;
		cout <<  isPerin(fir,sec) << "\n";
	}
}

 