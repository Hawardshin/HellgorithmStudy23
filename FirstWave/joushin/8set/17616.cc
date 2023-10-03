//날씨 흐림
#include<iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> link_forward[100001];
vector<int> link_backward[100001];
bool vis[100001];
int N,M,X;
int head,tail;
void dfs(bool isforward, int cur){
	if (vis[cur] == true)
		return;
	vis[cur] =true;
	if (isforward== true){
		tail++;
		for(int next : link_forward[cur]){
			dfs(isforward,next);
		}
	}
	else{
		head++;
		for(int next : link_backward[cur]){
			dfs(isforward,next);
		}
	}
}

void find_rank(){
	dfs(true,X);
	memset(vis,0,sizeof(vis));
	dfs(false, X);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N>>M>>X;
	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		link_forward[a].push_back(b);
		link_backward[b].push_back(a);
	}
	find_rank();
	cout << head<< " "<< N - tail + 1<< "\n";
}