#include <iostream>
#include <algorithm>
using namespace std;

int scv[3];
int dp[62][62][62];

int dfs(int a,int b,int c){
	if (a < 0)return dfs(0, b, c);
	if (b < 0)return dfs(a, 0, c);
	if (c < 0)return dfs(a, b, 0);
	
	if (a ==0 && b==0 && c ==0)
		return 0;
	else if (dp[a][b][c] != 1000)
		return dp[a][b][c];
	else{
			dp[a][b][c] = min(dp[a][b][c], dfs(a-9,b-3,c-1)+1);
			dp[a][b][c] = min(dp[a][b][c], dfs(a-9,b-1,c-3)+1);
			dp[a][b][c] = min(dp[a][b][c], dfs(a-3,b-9,c-1)+1);
			dp[a][b][c] = min(dp[a][b][c], dfs(a-3,b-1,c-9)+1);
			dp[a][b][c] = min(dp[a][b][c], dfs(a-1,b-9,c-3)+1);
			dp[a][b][c] = min(dp[a][b][c], dfs(a-1,b-3,c-9)+1);
			return (dp[a][b][c]);
	}
}
int main(){
	int N; 
	cin >>N;
	for(int i=0;i<N;i++)
		cin>>scv[i];
	for(int i=0;i<=60;i++){
		for(int j=0;j<=60;j++){
			for(int k=0;k<=60;k++) dp[i][j][k] = 1000;
		}
	}
	cout << dfs(scv[0],scv[1],scv[2]) << "\n";

}