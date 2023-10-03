//흐림
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ret[100001];
bool vis[100001]; //이 값을 사용했는지 안 사용했는지 넣는 것
int n,m;

void solve(){
	for(int i=1;i<=n;i++){
		if (vis[ret[i]]){
			cout<< -1 <<"\n";
			return;
		}
		vis[ret[i]]= true;
	}
	for(int i=1;i<=n;i++){
		cout<< ret[i] << " ";
	}
	cout << "\n";
}

int main(){
	cin >>n>>m;
	int x,y;
	for(int i=1;i<=n;i++) ret[i] = i;
	for(int i=0;i<m;i++){
		cin >> x>>y;
		ret[x]++; ret[y]--;
	}
	solve();
}