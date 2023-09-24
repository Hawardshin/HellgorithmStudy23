#include <iostream>
#include <algorithm>
//무게, 가치
using namespace std;

/*
5 10

3 8

4 7

1 9

5 6

2 1

답: 25
*/

int DP[101][100001];//해당 무게를 지고 있을 때 지닐 수 있는 최대 가치를 담는다.
int n,k; //물품 갯수와 견딜 수 있는 최대 무게
//무게, 가치
//

int main(){
	cin >> n>> k;
	int a,b;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int j=1;j<=k;j++){
			if (j >= a)
				DP[i][j] =max(DP[i-1][j], b + DP[i-1][j-a]);
			else 
				DP[i][j] = DP[i-1][j];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=k;j++){
	// 		cout << DP[i][j] << ",";
	// 	}
	// 	cout << "\n";
	// }
	int maxret =0;
	for(int i=0;i<=k;i++){
		maxret=max(maxret,DP[n][i]);
	}
	cout << maxret<<'\n';
}