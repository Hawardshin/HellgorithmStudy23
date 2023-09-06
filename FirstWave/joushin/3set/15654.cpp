#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int arr[9];
bool vis[9];

//배열의 깊이
//더 필요한 원소의 갯수 : M - depth 필요
//가능한 깊이 : N - now
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
		if (vis[i]== false){
			vis[i] = true;
			store.push_back(arr[i]);
			dfs(store_num+1);
			store.pop_back();
			vis[i] = false;
		}
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