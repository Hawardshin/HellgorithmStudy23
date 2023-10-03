#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int table[126][126];
int lentab[126][126];
int N;


void solve(){// X + N*Y를 위치라고 생각한다.
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
	Q.push({table[0][0],0});
	while (!Q.empty()){
		auto q = Q.top();
		Q.pop();
		int x = q.second%N;
		int y = q.second/N;
		lentab[y][x] =q.first;
		for(int i=0;i<4;i++){
			int ty = y + dy[i];
			int tx = x + dx[i];
			if (ty < 0 || tx < 0 || ty >=N || tx >= N)
				continue;
			int next_val =q.first + table[ty][tx];
			if (lentab[ty][tx] == -1  || next_val < lentab[ty][tx]){
				lentab[ty][tx] = next_val;
				Q.push({next_val, ty*N+tx});
			}
		}
	}
}

void input(){
	int idx = 1;
	while (1){
		cin >>N;
		if (N == 0)
			return;
		memset(table,-1,sizeof(table));
		memset(lentab,-1,sizeof(lentab));
		// memset(vis,0,sizeof(vis));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> table[i][j];
			}
		}
		lentab[0][0] = table[0][0];
		solve();
		cout << "Problem "<< idx << ": "<< lentab[N-1][N-1] <<"\n";
		idx++;

	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
}