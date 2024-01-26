#include <iostream>
#include <queue>
//걸린 시간 : 30분 
//직전에 풀었던 문제에서 아이디어 하나만 추가하면 돼서 쉽게 풀었다.
using namespace std;
/*
방문한 칸의 갯수
낮과밤
지도 (벽,빈칸)
부순벽의 갯수
낮에만 부술 수 있다.
즉, 홀수일때만 부술 수 있다.
*/
bool table[1001][1001];
bool vis[1001][1001][11];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
typedef struct s_move{
	int x;
	int y;
	int dist;
	int broken;
}t_move;

int N,M,K;
int main(){
	cin >> N>> M>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char tmp;
			cin >>tmp;
			table[i][j] = tmp - '0';
		}
	}
	queue<t_move> Q;
	Q.push({0,0,1,0});
	while(!Q.empty()){
		auto q = Q.front();
		Q.pop();
		if (q.x == M-1 && q.y == N-1){
			cout << q.dist << "\n";
			return 0;
		}
		for(int i=0;i<4;i++){
			int tx = q.x + dx[i];
			int ty = q.y + dy[i];
			if (ty <0 || tx < 0 || ty >=N || tx >=M)
				continue;
			//다음 이동이 빈칸인 경우
			if (table[ty][tx] == 0 && !vis[ty][tx][q.broken]){
				vis[ty][tx][q.broken] = true;
				Q.push({tx,ty,q.dist+1,q.broken});
			}//다음 이동이 벽인 경우
			else if (table[ty][tx] == 1 && q.broken < K &&!vis[ty][tx][q.broken+1]){
				if (q.dist%2 == 1){ //낮인 경우
					vis[ty][tx][q.broken+1] = true;
					Q.push({tx,ty,q.dist+1,q.broken+1});
				}
				else{ //밤인 경우
					Q.push({q.x,q.y,q.dist+1,q.broken});
				}
			}
		}
	}
	cout << "-1\n";
}