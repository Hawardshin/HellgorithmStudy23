#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M;

int table[301][301];
bool vis[301][301];
int to_delete[301][301];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
bool is_all_zero = false;
void pirnt_table(){
	for(int i=0;i < N;i++){
		for(int j=0;j<M;j++){
			cout << table[i][j];
		}
		cout << "\n";
	}
	cout<<"---------------\n";
}

void bfs(int y,int x){
	vis[y][x] = true;
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
			// cout << "t::" << ty << tx <<"\n";
			if (ty <0 || tx < 0 || ty >=N || tx >= M)
				continue;
			if (vis[ty][tx])
				continue;
			if (table[ty][tx] != 0)
				Q.push({ty,tx});
			vis[ty][tx] = true;
		}
	}
}

bool check_island(){
	int island_num = 0;
	for(int i=0; i < N;i++){
		for(int j=0;j < M;j++){
			if (vis[i][j] == 0 && table[i][j] != 0){
				// cout << "what?" << i << j <<"\n";
				bfs(i,j);
				island_num++;
				if (island_num == 2)
					return (true);
			}
		}
	}
	if (island_num == 0){
		is_all_zero = true;
		return true;
	}
	return false;
}

void make_to_delete(int y,int x){
	vis[y][x] = true;
	queue<pair<int, int> >Q;
	Q.push({y,x});
	while (!Q.empty()){
		auto q_front = Q.front();
		Q.pop();
		int my = q_front.first;
		int mx = q_front.second;
		for(int i=0;i < 4;i++){
			int ty = my + dy[i];
			int tx = mx + dx[i];
			if (ty <0 || tx < 0 || ty >=N || tx >= M)
				continue;
			if (vis[ty][tx])
				continue;
			if (table[ty][tx] != 0){
				vis[ty][tx] = true;
				Q.push({ty,tx});
			}
			else 
				to_delete[my][mx]++;
		
		}
	}
}

void melting(){
	for(int i=0;i<N;i++){
		for(int j=0; j<M;j++){
			if (table[i][j] != 0){
				table[i][j] = table[i][j] - to_delete[i][j];
				if (table[i][j] < 0)
					table[i][j] = 0;
			}
		}
	}
}

void day_after(){
	for(int i=0;i < N;i++){
		for(int j=0;j<M;j++){
			if (table[i][j] != 0){
				make_to_delete(i,j);
				melting();
				return ;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=0;i < N;i++){
		for(int j=0; j<M;j++){
			cin >> table[i][j];
		}
	}
	int ret = 0;

	while (1){
		if (check_island())
			break;
		ret++;
		memset(vis,0,sizeof(vis));
		day_after();
		memset(to_delete,0,sizeof(to_delete));
		// pirnt_table();
		memset(vis,0,sizeof(vis));
		// cout << "what?\n"; 
	}
	if (is_all_zero)
		cout << 0 <<"\n";
	else
		cout << ret << "\n";
}