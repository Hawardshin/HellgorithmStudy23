#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int N,K;
pair<int,int> trip[101][2];
int dp[100001][101];
#define TIME first 
#define MONEY second 
void input(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> N >> K;
	for(int i=0;i<N;i++){
		int a,b,c,d;
		cin >> a >>b>>c >>d;
		trip[i][0] = {a,b};
		trip[i][1] = {c,d};
	}
	memset(dp,-1,sizeof(dp));
}

int recur(int time, int pos){
	if (pos >= N) return 0;
	if (dp[time][pos] != -1) return dp[time][pos];
	dp[time][pos] = -1000000;
	if (time + trip[pos][0].TIME <= K)
		dp[time][pos] = max(dp[time][pos], recur(time+trip[pos][0].TIME,pos+1) + trip[pos][0].MONEY);
	if (time + trip[pos][1].TIME <= K)
		dp[time][pos] = max(dp[time][pos],recur(time+trip[pos][1].TIME, pos+1) + trip[pos][1].MONEY);
	return dp[time][pos];
}

void solve(){
	cout << recur(0,0) << "\n";
}

int main(){
	input();
	solve();
}
