#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int DP[10001];//현재 쓰는 사탕의 갯수,.사용한 돈의 양 => 배열에 들어가는 값은 칼로리양
int input[5001][2];//[0]사탕의 숫자, [1]돈의 양
int main(){
	while(1){
		double tmp;
		cin >> n >> tmp;
		if (n == 0 && tmp == 0.00)
			return (0);
		m = tmp * 100;
		int maxret = 0;
		for(int i=1;i<=n;i++){
			int cost;
			cin>> input[i][0] >> tmp;
			cost = tmp*100+0.5;
			input[i][1]=cost;
		}
		for(int i=1;i<=n;i++){
			int calo = input[i][0];
			int cost = input[i][1];
			for(int j=1;j<=m;j++){
				if (j-cost >=0){
					DP[j] = max(DP[j],DP[j-cost] +calo);
					maxret = max(maxret,DP[j]);
				}
			}
		}
		cout << maxret <<"\n";
		memset(DP,0,sizeof(DP));
	}
}

/*
2 8.00
700 7.00
199 2.00

[000... 700]
[]
*/