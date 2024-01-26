/*
N*N 100*100
(1,1) (N,N)
M :각 방들에 있는 스위치 20000
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define  X first
#define  Y second
using namespace std;

bool l_vis[101][101]; //불을 한번 킨 방 목록 
bool n_vis[101][101]; // 현재 bfs 도중 방문한 방들
bool table[101][101]; //현재 지도의 그림
vector<pair<int,int>> light_switch[101][101];
int N,M;
int ret = 1;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int	lightUp(int x,int y){
	int lup = 0;
	if (l_vis[y][x] == true)
		return 0;
	for(auto it:light_switch[y][x]) {
		if (table[it.Y][it.X] ==false){
			lup++;
			table[it.Y][it.X] = true;
		}
	}
	l_vis[y][x] = true;
	return lup;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x,y,a,b;
		cin >>x>>y>>a>>b;
		light_switch[y][x].push_back({a,b});
	}
	queue<pair<int,int>>Q;
	table[1][1]=true;

	bool isDone = false;
	while (!isDone){
		isDone = true;
		Q.push({1,1});
		n_vis[1][1]=true;
		while (!Q.empty()){
			auto q = Q.front();
			Q.pop();
			int light_up= lightUp(q.X,q.Y);
			if (light_up != 0){
				ret += light_up;
				isDone = false;
			}
			for(int i=0;i<4;i++){
				int nx = q.X + dx[i];
				int ny = q.Y + dy[i];
				if (nx <0 || ny < 0 || nx > N || ny > N)
					continue;
				if (table[ny][nx] == false)
					continue;
				if (n_vis[ny][nx] == true)
					continue;
				int light_up= lightUp(nx,ny);
				if (light_up != 0){
					ret += light_up;
					isDone = false;
				}
				n_vis[ny][nx] =true;
				Q.push({nx,ny});
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++) n_vis[i][j] = false;
		}
	}
	cout << ret<< "\n";
}
