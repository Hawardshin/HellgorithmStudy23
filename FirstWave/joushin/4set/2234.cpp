#include <iostream>
#include <queue>

using namespace std;
#define TABLE_SIZE 102
int table[TABLE_SIZE][TABLE_SIZE];//벽에 대한 정보가 있는 배엻
int vis_room[TABLE_SIZE][TABLE_SIZE];//BFS 할 때 쓸 배열
int room_num[TABLE_SIZE][TABLE_SIZE];//몇번방에 해당하는지 0번부터 시작.
int room_size_ar[102];//몇번 인덱스에 해당하는 room에 대해서 room의 크기
int room_idx;
int max_size = 1;
int max_sum;
//남,동,북,서
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int N,M;
//4개의 함수는 벽이 있는지를 검사하는 함수입니다.
bool check_west(int a){
	if (a & 1)
		return true;
	return false;
}
bool	check_north(int a){
	if (a & (1 << 1))
		return true;
	return false;
}

bool check_east(int a){
	if (a & (1 << 2))
		return true;
	return false;
}

bool check_south(int a){
	if (a & (1 << 3))
		return true;
	return false;
}

//----------------------------//

void	bfs(int y,int x){
	int room_size = 1;
	if (vis_room[y][x] != 0)
		return;
	queue<pair<int, int> > Q;
	Q.push({y,x});
	vis_room[y][x] = 1;
	room_num[y][x] = room_idx;
	while (!Q.empty()){
		auto q_f = Q.front();
		Q.pop();
		int mx = q_f.second;
		int my = q_f.first;
		for(int i=0;i<4;i++){//남,동,북,서
			int tx = mx + dx[i];
			int ty = my + dy[i];
			if (i == 0 && check_south(table[my][mx]))//북
				continue;
			if (i == 1 && check_east(table[my][mx]))//동
				continue;
			if (i == 2 && check_north(table[my][mx]))//남
				continue;
			if (i == 3 && check_west(table[my][mx]))//서
				continue;
			if (vis_room[ty][tx]!= 0)
				continue;
			room_size++;
			vis_room[ty][tx] = vis_room[my][mx] +1;
			if (max_size < room_size)
				max_size = room_size;
			room_num[ty][tx] = room_idx;
			Q.push({ty,tx});
		}
	}
	room_size_ar[room_idx] = room_size;
	room_idx++;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> N>>M;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++) cin >> table[i][j];
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++) bfs(i,j);
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			//계속해서 동쪽과 남쪽만 확인하면서 벽을 부셔보면 된다.
			//동쪽
			int next_y = i;
			int next_x = j+1;
			if (next_x != N){
				if (room_num[i][j] != room_num[next_y][next_x]){
				 int sum = room_size_ar[room_num[i][j]] + room_size_ar[room_num[next_y][next_x]];
				 if (sum > max_sum)
				 	max_sum = sum;
				}
			}
			//남쪽
			next_y = i+1;
			next_x = j;
			if (next_y != M){
				if (room_num[i][j] != room_num[next_y][next_x]){
				 int sum = room_size_ar[room_num[i][j]] + room_size_ar[room_num[next_y][next_x]];
				 if (sum > max_sum)
				 	max_sum = sum;
				}
			}
		}
	}
	cout << room_idx << "\n" << max_size<< "\n" << max_sum << "\n";
}