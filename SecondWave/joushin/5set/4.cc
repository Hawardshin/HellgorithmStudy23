#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define WATER -214748364
#define ROCK -100000000
#define DESTINATION -1000000000
int R,C;
int table[51][51];
bool vis[51][51];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};
queue<pair<int,int> > GoQ;
queue<pair<int,int> > WaterQ;
int ret =0;

void input(){
	cin >>R >> C;
	char a;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> a;
			if (a == 'D') table[i][j] = DESTINATION;
			else if (a == 'S') GoQ.push({i,j});
			else if (a == 'X') table[i][j]= ROCK;
			else if (a == '*'){
				WaterQ.push({i,j});
				table[i][j] = WATER;
			}
		}
	}
}

void	waterBFS(){
	queue<pair<int,int> > nQ;
	while (!WaterQ.empty()){
		auto a = WaterQ.front();
		WaterQ.pop();
		for(int i=0;i<4;i++){
			int ny = a.first + dx[i];
			int nx = a.second + dy[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (table[ny][nx] == ROCK || table[ny][nx] == WATER || table[ny][nx] == DESTINATION)
				continue;
			table[ny][nx] = WATER;
			nQ.push({ny,nx});
		}
	}
	WaterQ = nQ;
}

void	GoBFS(){
	queue<pair<int,int> > nQ;
	while (!GoQ.empty())
	{
		auto a = GoQ.front();
		GoQ.pop();
		vis[a.first][a.second] =true;
		for(int i=0;i<4;i++){
			int ny = a.first + dy[i];
			int nx = a.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (table[ny][nx] == ROCK || table[ny][nx] == WATER)
				continue;
			if (vis[ny][nx])
				continue;
			if (table[ny][nx] == DESTINATION){
				cout << ret+1 << "\n";
				ret = -1;
				return ;
			}
			vis[ny][nx] = true;
			nQ.push({ny,nx});
		}
	}
	GoQ = nQ;
}

int main(){
	input();
	while (!GoQ.empty()){
		waterBFS();
		GoBFS();
		if (ret == -1)
			return 0;
		ret++;
	}
	cout << "KAKTUS\n";
}
