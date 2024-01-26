/*
N*M (1000*1000)
- 빈칸 : . 
- 막힘 : #
- 성 : 1~9
- S1~S10 (성마다 이동할 수 있는 거리)
출력: 각각 가진 성의 수 출력
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct s_move{
	int x;
	int y;
	int	dist;
}t_move;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int table[1001][1001];

int S[11];
int castle_cnt[11];
int N,M,P;

queue<t_move> BQ[11]; //짝수 일때 사용
queue<t_move> NQ[11]; //홀수 일때 사용

bool isDone(){
	for(int i=1;i<=P;i++){
		if (!NQ[i].empty() || !BQ[i].empty())
			return false;
	}
	return true;
}

void	oneBfs(int player,queue<t_move>& Q, queue<t_move> &nextQ){
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int tx = q.x+dx[i];
			int ty = q.y+dy[i];
			if (tx < 0 || ty < 0 || tx >= M || ty >= N)
				continue;
			if (table[ty][tx] == 0){
				table[ty][tx] = player;
				castle_cnt[player]++;
				if (S[player] > q.dist)
					Q.push({tx, ty, q.dist+1});
				else if (S[player] == q.dist)
					nextQ.push({tx,ty,1});
			}
		}
	}
}

// 첫번째 bfs를 돌린다.
	//길이가 S까지 범위로 bfs를 돌리고 길이가 0이 된 경우를 저장해둔다.(이후 bfs에 사용)
// P번째 bfs까지 돌린다.
// 저장해둔 위치부터 bfs를 다시 돌린다.
int main(){
	cin >> N >> M >> P;
	for(int i=0;i<P;i++) cin >> S[i+1];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char tmp;
			cin >> tmp;
			if (tmp =='.')
				table[i][j] = 0;
			else if (tmp =='#')
				table[i][j] = -1;
			else {
				table[i][j] = tmp - '0';
				BQ[tmp - '0'].push({j,i,1});
				castle_cnt[tmp-'0']++;
			}
		}
	}
	int day = 0;
	while (!isDone()){
		if (day % 2 ==0){
			for(int i=1;i<=P;i++) oneBfs(i,BQ[i],NQ[i]);
		}else {
			for(int i=1;i<=P;i++) oneBfs(i,NQ[i],BQ[i]);
		}
		day++;
	}
	for(int i=1;i<=P;i++) cout << castle_cnt[i] << " ";
}