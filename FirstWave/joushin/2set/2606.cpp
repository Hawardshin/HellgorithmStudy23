#include <iostream>

using namespace std;
int ret;
int N,M;
bool links[101][101];
bool computer[101];
void dfs(int start){
	for(int i=1;i <= N;i++){
		if (links[i][start]){
			links[i][start] = 0;
			links[start][i] = 0;
			if (!computer[i]){
				computer[i] = true;
				ret++;
			}
			if (!computer[start]){
				computer[start] = true;
				ret++;
			}
			dfs(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a,b;
	bool is_one = false;
	for (int i=0;i < M;i++){
		cin >> a >>b;
		if (!is_one &&(a == 1 || b == 1))
			is_one = true;
		links[a][b] = 1;
		links[b][a] = 1;
	}
	dfs(1);
	ret--;
	if (!is_one)
		ret = 0;
	cout << ret <<"\n";
}
