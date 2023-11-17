#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector<pair<int,int>> input;
int ret= 0;
int DP[101];
int max_size=0;
int calcDp(int i){
	int now_num = input[i].second;
	int calc_ret=1;
	for(int j=0; j <i;j++){
		if (input[j].second < now_num)
			calc_ret = max(DP[j]+1,calc_ret);
	}
	max_size = max(max_size, calc_ret);
	return calc_ret;
}

int main(){
	cin >> N;
	int a,b;

	for(int i=0;i<N;i++){
		cin >> a >> b;
		input.push_back({a,b});
	}
	DP[0] = 1;
	sort(input.begin(),input.end());
	for(int i=1;i<N;i++) DP[i] = calcDp(i);
	
	cout << N-max_size << "\n";
}