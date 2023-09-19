#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define NUM_SIZE 1000001
using namespace std;
int N;
int input[NUM_SIZE];
int DP[NUM_SIZE];
int all_max =0;
int max_idx;
//이곳에는 해당 위치를 가장 긴 꼬리라고 생각하는 값을 넣을 것이다.

int find_max(int ar_idx){
	int maax = 0;
	for(int i=0;i< ar_idx;i++){
		if (input[i] < input[ar_idx])
			maax = max(maax, DP[i]);
	}
	maax++;
	if (all_max < maax){
		max_idx = ar_idx;
		all_max = maax;
	}
	return (maax);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) cin >> input[i];
	
	for(int i=0;i<N;i++){
		DP[i] = 0;
		DP[i] = find_max(i);
	}
	cout << all_max << "\n";
	int bef = 1000000001;
	stack<int> ret;
	for(int i =max_idx;i >=0;i--){
		if (DP[i] == all_max && input[i] < bef){
			all_max--;
			bef = input[i];
			ret.push(i);
		}
		if (all_max == 0){
			while (!ret.empty()){
				cout << input[ret.top()] << " ";
				ret.pop();
			}
			cout << "\n";
			break;
		}
	}
	
}