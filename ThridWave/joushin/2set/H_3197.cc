#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define X first 
#define Y second 

using namespace std;

/* 
- X: 빙판
- .: 물
- L: 오리
*/
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char duck='1';
char table[1501][1501];
bool vis[1501][1501];
bool wvis[1501][1501];
int R,C;
queue<pair<int,int>> LQ[2];
queue<pair<int,int>> RQ[2];
queue<pair<int,int>> WQ[2];
void print_table(){
	cout << "-----------------------------\n";
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << table[i][j];
		}
		cout << "\n";
	}
}

bool leftBfs(int day){
	while (!LQ[day%2].empty()){
		auto q = LQ[day%2].front();
		LQ[day%2].pop();
		vis[q.Y][q.X] = true;
		for(int i=0;i<4;i++){
			int ny = q.Y + dy[i];
			int nx = q.X + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (table[ny][nx] == '2')
				return true;
			if (vis[ny][nx] == true)
				continue;
			if (table[ny][nx] == '.'){
				vis[ny][nx] =true;
				table[ny][nx] = '1';
				LQ[day%2].push({nx,ny});
			}
			else if (table[ny][nx] == 'X'){
				vis[ny][nx] = true;
				table[ny][nx] = '1';
				LQ[(day+1)%2].push({nx,ny});
			}
			
		}
	}
	return false;
}

bool rightBfs(int day){
		while (!RQ[day%2].empty()){
		auto q = RQ[day%2].front();
		RQ[day%2].pop();
		vis[q.Y][q.X] = true;
		for(int i=0;i<4;i++){
			int ny = q.Y + dy[i];
			int nx = q.X + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (table[ny][nx] == '1')
				return true;
			if (vis[ny][nx] == true)
				continue;
			if (table[ny][nx] == '.'){
				vis[ny][nx] =true;
				table[ny][nx] = '2';
				RQ[day%2].push({nx,ny});
			}
			else if (table[ny][nx] == 'X'){
				vis[ny][nx] = true;
				table[ny][nx] = '2';
				RQ[(day+1)%2].push({nx,ny});
			}
		}
	}
	return false;
}

void waterBfs(int day){
	if (day == 0){
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if (table[i][j] == '.'){
					WQ[0].push({j,i});
					wvis[i][j] = true;
				}
			}
		}
	}
	while (!WQ[day%2].empty()){
		auto q = WQ[day%2].front();
		WQ[day%2].pop();
		wvis[q.Y][q.X] = true;
		for(int i=0;i<4;i++){
			int ny = q.Y + dy[i];
			int nx = q.X + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (wvis[ny][nx] == true)
				continue;
			if (table[ny][nx] == '.'){
				wvis[ny][nx] =true;
				WQ[day%2].push({nx,ny});
			}
			else if (table[ny][nx] == 'X'){
				wvis[ny][nx] = true;
				table[ny][nx] = '.';
				WQ[(day+1)%2].push({nx,ny});
			}
		}
	}
}


int main(){
	cin >>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			char tmp;
			cin >>tmp;
			if (tmp == 'L'){
				tmp = duck;
				duck++;
				if (LQ[0].empty())
					LQ[0].push({j,i});
				else
					RQ[0].push({j,i});
			}
			table[i][j] = tmp;
		}
	}
	// print_table();
	//BFS좌우 진행
	//진행하다가 벽을 만나면 벽을 현재 다음 큐에 Push 후 해당 위치 vis처리, 해당 맵을 현재 오리로 변경
	int day = 0;
	while (true){
		if (leftBfs(day))
		{
			cout << day<< "\n";
			return 0;
		}
		if (rightBfs(day)){
			cout << day+1 << "\n";
			return 0;
		}
		waterBfs(day);
		day++;
	}
}