#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char map[21][21];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int R,C;
bool vis[26];//A부터 Z까지
int max_ = 0;
void dfs(int depth,int y,int x){
	for(int i=0;i<4;i++){
		int my = y+dy[i];
		int mx = x+dx[i];
		if (my ==0 || mx == 0 || mx == C+1 || my == R+1)
			continue;
		if (!vis[map[my][mx]-'A']){
			vis[map[my][mx]-'A'] = true;
			dfs(depth+1,my,mx);
			vis[map[my][mx]-'A'] = false;
		}
	}
	if (max_ < depth)
			max_ = depth;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> R>>C; cin.ignore();
	string tmp;
	for(int i=1;i <=R;i++){
		getline(cin,tmp);
		for(int j=1;j<=C;j++) map[i][j] = tmp[j-1];
	}
	vis[map[1][1] - 'A']=true;
	dfs(1,1,1);
	cout << max_ << "\n";
}