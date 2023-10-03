#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

bool input[100001];
int dp[10001];
vector<int>num;
int n,k;
/*
3 15
1
5
12

1*15 ->15
5*3 ->3
12*1 1*3 ->4

  | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 | 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
2 | 0 1 0 2 0 3 0 4 0  5  0  6  0  7  0
3 | 0 0 1 0 0 2 0 0 3  0  0  4  0  0  5
4 | 0 0 0 1 0 0 0 2 0  0  0  3  0  0  0
*/
int main(){
	cin >> n >> k;
	int tmp;
	for(int i=0;i<n;i++) {
		cin >> tmp;
		if (input[tmp]==false){
			num.push_back(tmp);
		}
		input[tmp] =true;
	}
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){
		for(int j=1;j * num[i]<=k;j++){
			if (dp[j*num[i]] !=0)
				dp[j * num[i]] = min(j,	dp[j * num[i]]);
			else
				dp[j * num[i]] = j;
		}
		for(int j=1;num[i] + j<=k;j++){
			if (dp[j] !=0){
				if (dp[num[i] + j]==0)
					dp[num[i] + j] =  dp[num[i]] +dp[j];
				else 
					dp[num[i] + j] =  min( dp[num[i]] +dp[j], dp[num[i] + j]);
			}
		}
	}
	if (dp[k] == 0)
		dp[k] = -1;
	cout << dp[k] << "\n";
}