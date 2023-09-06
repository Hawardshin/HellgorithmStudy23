#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int arr[9];
bool vis[9];

vector<int> store;
void dfs(int store_num){
	if (store_num == M)
	{
		for(int i=0;i < M;i++){
			cout << store[i];
			if (i != M -1)
				cout << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=0;i < N;i++){
			store.push_back(arr[i]);
			dfs(store_num+1);
			store.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=0;i < N;i++){
		cin >> arr[i];
	}
	sort(arr, arr+N);
	dfs(0);
}