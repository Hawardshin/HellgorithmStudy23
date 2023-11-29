#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int,int> input[16];
int max_ret;
void recur(int idx,int left_day,int money){
	if (idx == N ){
		if (left_day==0)
		max_ret = max(max_ret,money);
		return;
	}
	if (left_day == 0){
		recur(idx+1,input[idx].first-1, money+ input[idx].second);
		recur(idx+1,0,money);
	}
	else {
		recur(idx+1,left_day-1,money);
	}
}

int main(){
	cin >> N;
	long long ret = 1;
	int a,b;
	for(int i=0;i<N;i++){
		cin >>a >> b;
		input[i] = {a,b};
	}
	recur(1,0,0);
	recur(1,input[0].first - 1,input[0].second);
	cout << max_ret;
}