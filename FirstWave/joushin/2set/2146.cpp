#include <iostream>
#include <queue>
using namespace std;
int N;
int input[103][103];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int area_val;
int min_len = 2147483647;
void init(int i, int j){
	queue<pair<int,int> > Q;
	Q.push({i,j});//y,x
	area_val--;
	while (!Q.empty()){
		auto a = Q.front();
		int my = a.first;
		int mx = a.second;
		Q.pop();
		for(int i=0;i<4;i++){
			int ty = my+dy[i];
			int tx = mx + dx[i];
			if (ty < 0 || tx < 0 || ty >=N ||tx >= N)
				continue;
			if (input[ty][tx] != 1)
				continue;
			input[ty][tx] = area_val;
			Q.push({ty,tx});
		}
	}
}

void find_mini(int i,int j){//y,x
	int start_id = input[i][j];
	queue<pair<int,int> >Q;
	Q.push({i,j});//y,x
	while (!Q.empty()){
		auto a = Q.front();
		Q.pop();
		int my = a.first;
		int mx = a.second;
		for(int i=0;i<4;i++){
			int ty = my+dy[i];
			int tx = mx + dx[i];
			if (ty < 0 || tx < 0 || ty >=N ||tx >= N)
				continue;
			if (input[ty][tx] == start_id)//같은 섬이면
				continue;
			else if (input[ty][tx] < 0)//다른 섬이면
			{
				// cout << "다음으로 도착할 곳" << input[ty][tx] << "\n";
				if (min_len >  input[my][mx]){
					min_len = input[my][mx];
				}
				continue;
			}
			if (input[ty][tx] == 0){//아직 방문하지 않은 곳이라면 또는 이미 방문했는데 이전에 방문했던 거리보다 더 짧아진 경우
				// cout << "ty :"<< ty << "tx:" <<tx << "\n";
				input[ty][tx] = input[my][mx] + 1;
				Q.push({ty,tx});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){//input
		for(int j=0;j<N;j++){
			cin >> input[i][j];
		}
	}
	for(int i=0;i<N;i++){//init island
		for(int j=0;j<N;j++){
			if (input[i][j] == 1)
				init(i,j);
		}
	}
	for(int i=0;i<N;i++){//min value find
		for(int j=0;j<N;j++){
			if (input[i][j] < 0)
				find_mini(i,j);
		}
	}
	cout << min_len << "\n";

}