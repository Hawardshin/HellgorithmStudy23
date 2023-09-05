//1. 맵에서 하나씩 선택해서 지우고 bfs 진행 -> 시간 복잡도 대폭발
//2. 맵을 bfs하다가 특정 조건에서 1개를 지우고 진행 -> 특정 조건으로 생각해볼껀
//맵에서 최소 값으로 이동하려면 왼쪽과 위쪽 이동을 최소화하는 걸 이용할 수도 있을 것 같다.
//3. 시작점에서 bfs 끝점에서 bfs를 해서 각자 다른 값으로 채운다.
//3-1. 그러면 끝점에서 부터 거리를 가진 배열과 시작점에서부터 거리를 가진 배열 2개가 나온다.
//3-2. 두개의 배열이 나오면, 장애물만 선택해서 장애물을 없앴을 때 나오는 거리를 합쳐본다.
//이걸 장애물이 있는 모든 곳에 대해서 하면 최소값을 구할 수 있다.

#include <iostream>
#include <queue>

using namespace std;
int start_table[1001][1001];
int end_table[1001][1001];
bool vis[1001][1001];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int N,M;
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >>start_table[i][j];
			end_table[i][j] = start_table[i][j];
		}
	}
}

