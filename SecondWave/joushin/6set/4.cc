
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
int DP[1001];
vector<int> ret2[1001];
int N;
int max_s = 1;
int max_idx;
int calcDp(int i){
	int ret =1;
	for(int j=0;j<i;j++){
		if (arr[j] < arr[i]){
			if (ret < DP[j] +1){
				ret = DP[j] + 1;
				ret2[i] = ret2[j];
				ret2[i].push_back(arr[i]);
			}
		}
	}
	if (max_s < ret){
		max_s = ret;
		max_idx = i;
	}
	if (ret2[i].size() == 0)
		ret2[i].push_back(arr[i]);
	max_s = max(ret, max_s);
	return ret;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> arr[i];
	DP[0] = 1;
	ret2[0].push_back(arr[0]);
	for(int i=1;i<N;i++) DP[i] = calcDp(i);
	cout << max_s << "\n";
	for(auto a: ret2[max_idx]){
		cout << a << " ";
	}
	cout << "\n";
}

/*
4
2 1 2 5

7 
5 6 7 1 2 3 4
4
1 2 3 4 

*/