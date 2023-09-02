#include <iostream>
#include <queue>
#include <utility>
#define Y first
#define X second
using namespace std;
bool vis[103][103];
int map[103][103];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
// void print_all(){
// 	for(int i=0; i< 10; i++){
// 		for(int j=0; j < 10; j++){
// 			 cout << map[i][j];
// 		}
// 		cout << "\n";
// 	}
// 	cout << "\n";
// }
int main(){
	int N,M;
	cin >> N >> M;
	string input;
	cin.ignore();
	for(int i=1;i <= N;i++){
		getline(cin,input);
		for(int j=0;j < M;j++) map[i][j+1] = input[j] - '0';
	}
	queue<pair<int,int>> Q;
	Q.push({1,1});
	vis[1][1] = true;
	while (!Q.empty()){
		pair<int, int>t = Q.front();
		Q.pop();
		int value = map[t.Y][t.X];
		for(int i =0;i <4;i++){
			int tx = t.X + dx[i];
			int ty = t.Y + dy[i];
			if (ty ==0 || tx == 0 || ty == N+1 ||tx == M + 1)
				continue;;
			if (map[ty][tx] && value && !vis[ty][tx]){
				Q.push({ty,tx});
				map[ty][tx] = value+1;
				vis[ty][tx] = true;
			}
		}
	}
	// print_all();
	cout << map[N][M] <<"\n";
}

