/*
dp[가방에 채워진 물건무게] = max(dp[가방무게 - 물건무게]+1, dp[가방무게 - 물건무게])

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define NUM first
#define WEG second
using namespace std;



int N,M,C;
int dp[21][1<<15];
int stone[14];
pair<int,int> calc[1<<15];//사용된 물건의 갯수, 무게
int dping(int bag, int check){
	int ret=0;
	if(dp[bag][check] >= 0) 
		return dp[bag][check];
  if(bag == M) 
		return dp[bag][check] = 0;
	for(int i=0;i<(1<<N);i++){
		if (i & check) 
			continue;
		if (calc[i].WEG <=C)
			ret = max(ret,dping(bag+1,check | i)+ calc[i].NUM);
	}
	return dp[bag][check] = ret;
}

int main(){
	cin >> N >> M >> C;
	int ret =0;
	for(int i=0;i<N;i++) cin >> stone[i];
	for(int i=0;i<(1<<N);i++){
		for(int j=0;j<N;j++){
			if (i & (1<<j)){
				calc[i].WEG+=stone[j];
				calc[i].NUM++;
			}
		}
	}
 memset(dp, -1, sizeof(dp));
	cout << dping(0,0) << "\n";
}