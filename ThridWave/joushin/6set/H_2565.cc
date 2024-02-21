#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

pair<int,int> bolt[101];
int dp[101];
int n;
int maxRet;

int calcDp(int i){
	int ret = 1;
	for(int j=i-1; j >=0;j--){
		if (bolt[j].Y < bolt[i].Y){
			ret = max(dp[j]+1,ret);
			maxRet = max(ret,maxRet);
		}
	}
	return ret;
}


int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin>> bolt[i].X >> bolt[i].Y;
	}
	sort(bolt,bolt+n);
	for(int i=0;i<n;i++){
		dp[i] = calcDp(i);
	}
	cout << n- maxRet <<"\n";
}