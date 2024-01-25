#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define WALL -2
#define EMPTY -1

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int Table[1001][1001];
int vis[1001][1001][11];
//0이 부순거 1이 안 부순거

//벽 : 1 을 -2로
//빈 공간 : 0을 -1로
int N,M,K;
typedef struct sqVal{
	int X;
	int Y;
	int move_len;
	int broken_num;
}qVal;


void Input(){
	cin >> N >> M >> K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char tmp;
			cin >> tmp;
			int input;
			tmp == '1' ? input = WALL : input = EMPTY;
			Table[i][j] = input;
		}
	}
}

int Bfs(){
	queue<sqVal> Q;
	Q.push({0,0,1,0});
	Table[0][0] = 0;
	while (!Q.empty()){
		auto q = Q.front();
		if (q.Y == N -1 && q.X == M-1)
			return (q.move_len);
		Q.pop();
		for(int i=0;i<4;i++){
			int tx = q.X + dx[i];
			int ty = q.Y + dy[i];
			if (tx < 0 || ty < 0 || ty >= N || tx>=M)
				continue;
			//빈경우
			if (Table[ty][tx] == EMPTY && !vis[ty][tx][q.broken_num]){
				vis[ty][tx][q.broken_num] = true;
				Q.push({tx,ty,q.move_len+1,q.broken_num});
			}
			if (Table[ty][tx] == WALL && q.broken_num < K && !vis[ty][tx][q.broken_num+1]){ // 벽 인경우
				vis[ty][tx][q.broken_num+1] =true;
				Q.push({tx,ty,q.move_len+1, q.broken_num+1});
			}
		}
	}
	return -1;
}




int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	Input();
	cout << Bfs() << "\n";
}