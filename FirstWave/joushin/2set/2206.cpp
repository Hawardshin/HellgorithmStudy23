//1. 맵에서 하나씩 선택해서 지우고 bfs 진행 -> 시간 복잡도 대폭발
//2. 맵을 bfs하다가 특정 조건에서 1개를 지우고 진행 -> 특정 조건으로 생각해볼껀
//맵에서 최소 값으로 이동하려면 왼쪽과 위쪽 이동을 최소화하는 걸 이용할 수도 있을 것 같다.
//3. 시작점에서 bfs 끝점에서 bfs를 해서 각자 다른 값으로 채운다. (채택)
//3-1. 그러면 끝점에서 부터 거리를 가진 배열과 시작점에서부터 거리를 가진 배열 2개가 나온다.
//3-2. 두개의 배열이 나오면, 장애물만 선택해서 장애물을 없앴을 때 나오는 거리를 합쳐본다.
//이걸 장애물이 있는 모든 곳에 대해서 하면 최소값을 구할 수 있다.

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int start_table[1001][1001];
int end_table[1001][1001];
bool vis[1001][1001];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
// [{-1,0},{0,1}] [{-1,0},{1,0}] [{-1,0},{0,-1}]
// [{0,1},{1,0}] [{0,1},{0,-1}] [{1,0},{0,-1}]

int cx1[6] = {-1,-1,-1,0, 0, 1};
int cy1[6] = { 0, 0, 0,1, 1, 0};
int cx2[6] = { 0, 1, 0,1, 0, 0};
int cy2[6] = { 1, 0,-1,0,-1,-1};
int N,M;


void bfs_start(int y,int x){
	vis[y][x] = true;
	start_table[y][x] = 1;
	queue<pair<int, int> >Q;
	Q.push({y,x});
	while (!Q.empty()){
		auto q_front = Q.front();
		int my = q_front.first;
		int mx = q_front.second;
		Q.pop();
		for(int i=0;i < 4;i++){
			int ty = my + dy[i];
			int tx = mx + dx[i];
			if (ty <0 || tx < 0 || ty >=N || tx >= M)
				continue;
			if (vis[ty][tx])
				continue;
			if (start_table[ty][tx] == 0){
				Q.push({ty,tx});
				start_table[ty][tx] = start_table[my][mx] + 1;
				vis[ty][tx] = true;
			}
		}
	}
}

void bfs_end(int y,int x){
	vis[y][x] = true;
	queue<pair<int, int> >Q;
	Q.push({y,x});
	end_table[y][x] = 1;
	while (!Q.empty()){
		auto q_front = Q.front();
		int my = q_front.first;
		int mx = q_front.second;
		Q.pop();
		for(int i=0;i < 4;i++){
			int ty = my + dy[i];
			int tx = mx + dx[i];
			if (ty <0 || tx < 0 || ty >=N || tx >= M)
				continue;
			if (vis[ty][tx])
				continue;
			if (end_table[ty][tx] == 0){
				Q.push({ty,tx});
				end_table[ty][tx] = end_table[my][mx] + 1;
				vis[ty][tx] = true;
			}
		}
	}
}

int main(){
	cin >> N >> M;
	cin.ignore();
	string tmp;
	for(int i=0;i<N;i++){
		getline(cin,tmp);
		for(int j=0;j<M;j++){
			if (tmp[j] == '1')
				start_table[i][j] = -1;
			else 
				start_table[i][j] = 0;
			end_table[i][j] = start_table[i][j];
		}
	}
	bfs_start(0,0);
	memset(vis,0,sizeof(vis));
	bfs_end(N - 1, M - 1);
	int min = start_table[N-1][M -1];
	if (min == 0)
		min = 2147483647;
	for(int i=0;i <N;i++){
		for(int j=0;j<M;j++){
			if (start_table[i][j] == -1){
				for(int a=0;a <6;a++){
					int x1 = j + cx1[a];
					int y1 = i + cy1[a];
					int x2 = j + cx2[a];
					int y2 = i + cy2[a];
					if (x1 < 0 || y1 < 0 || y2 < 0 || x2 < 0 || x1 >=M || x2>=M || y2 >= N || y1 >= N)
						continue;
					if (start_table[y1][x1] <= 0 || end_table[y2][x2] <= 0)
						continue;
					if (min > start_table[y1][x1] + end_table[y2][x2] + 1)
						min =start_table[y1][x1] + end_table[y2][x2] + 1;
				}
				for(int a=0;a <6;a++){
					int x1 = j + cx2[a];
					int y1 = i + cy2[a];
					int x2 = j + cx1[a];
					int y2 = i + cy1[a];
					if (x1 < 0 || y1 < 0 || y2 < 0 || x2 < 0 || x1 >=M || x2>=M || y2 >= N || y1 >= N)
						continue;
					if (start_table[y1][x1] <= 0 || end_table[y2][x2] <= 0)
						continue;
					if (min > start_table[y1][x1] + end_table[y2][x2] + 1)
						min =start_table[y1][x1] + end_table[y2][x2] + 1;
				}
			}
		}
	}
	if (min == 2147483647)
		min = -1;
	cout << min << "\n";
}