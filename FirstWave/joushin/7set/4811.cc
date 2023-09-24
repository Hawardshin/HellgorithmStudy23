#include <iostream>
//W갯수 몇개 남았는지 H갯수 몇개 남았는지를 인자로
//W 갯수 1개 H갯수 1  -> 1
//W 갯수 2개 H 갯수 2개 -> W 1개 H3개 W2개 H1개 , W2 개 H 0개 
//1  
//WH 답 1
//2 WHWH , WWHH 답 2
//3 WWWHHH WWHWHH WWHHWH WHWWHH WHWHWH 답 5
//일반식 DP[W][H] = DP[W-1][H+1] + DP[W][H-1]
#include <algorithm>
#define W_MAX 31 
#define H_MAX 31
using namespace std;
long long DP[W_MAX][H_MAX];

int main(){
	int a;
	for(int i=1;i<=30;i++) DP[0][i] = 1;
	for(int i=1;i<=30;i++){
		for(int j=0;j<=30;j++){
			DP[i][j] = (DP[i-1][j+1]);
			if (j != 0)
				DP[i][j]+=  DP[i][j-1];
		}
	}
	while(1){
		cin >>a;
		if (a == 0)
			return (0);
		cout << DP[a][0] << "\n";
	}
}