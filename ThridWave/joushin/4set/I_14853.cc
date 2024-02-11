#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N,K;
#define TIME first
#define COST second
#define TIMEMAX 100000
pair<int,int> walk[101];
pair<int,int> bike[101];
int dp[100001][101]; //dp[시간][위치] = 비용

int recur(int time, int pos){
	if (pos == 0) return 0;
	if (dp[time][pos] != -1) return dp[time][pos];
    dp[time][pos]=-1e9;
	if (time-walk[pos].TIME>=0)
		dp[time][pos] = max(dp[time][pos],recur(time-walk[pos].TIME,pos-1)+walk[pos].COST);
	if (time-bike[pos].TIME>=0)
		dp[time][pos] = max(dp[time][pos],recur(time-bike[pos].TIME,pos-1)+bike[pos].COST);
	return dp[time][pos];
}

int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		int a,b,c,d;
		cin >> a >> b>>c>>d;
		walk[i] = {a,b};
		bike[i] = {c,d};
	}
	memset(dp,-1,sizeof(dp));
	cout << recur(K,N)<<"\n";
}