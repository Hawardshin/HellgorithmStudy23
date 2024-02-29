#include <iostream>
#include <cstring>

using namespace std;
int n;
int m;
bool links[1001][1001];
bool vis[1001];
bool isGraph ;
int cnt = 0;
void dfs(int idx){
	vis[idx] = true;
	cnt++;
	for(int i=1;i<=m;i++){
		if (links[idx][i] == true){
			if (!vis[i]){
				dfs(i);
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>m;
		int x;
		cin >>x;
		isGraph = false;
		memset(links,0,sizeof(links));
		memset(vis,0,sizeof(vis));
		for(int j=0;j<x;j++){
			int a,b;
			cin >> a>>b;
			links[a][b] = true;
			links[b][a] = true;
		}
		vis[1] = true;
		dfs(1);
		if (x != m-1)
			isGraph =true;
		if (cnt != m)
				isGraph = true;
		cnt = 0;
		if (isGraph)
			cout << "graph\n";
		else 
			cout << "tree\n";
	}
}