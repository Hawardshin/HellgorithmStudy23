#include <iostream>
#include <tuple>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int L=1, R=1, C=1;
int map[31][31][31];
bool vis[31][31][31];
int dz[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dx[6] = {0,0,1,0,0,-1};
// void print_map(){
// 	for(int i=0;i < 3; i++){
// 		for(int j=0;j < 4; j++){
// 			for(int k=0; k<5; k++){
// 				cout<< map[i][j][k];
// 			}
// 			cout << "\n";
// 		}
// 		cout << "\n";
// 	}
// }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sx,sy,sz,ex,ey,ez;
	while (1){
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C==0)
			return (0);
		cin.ignore();
		string tmp_input;
		for(int floor=0; floor < L; floor++){
			for(int i=0; i < R; i++){
				getline(cin, tmp_input);
				for(int j=0;j < C;j++){
					map[floor][i][j] = tmp_input[j];
					if (tmp_input[j] == 'E'){
						map[floor][i][j] = 'E';
						ez = floor;
						ey = i;
						ex = j;
					}else if (tmp_input[j] == 'S'){
						map[floor][i][j] = 1;
						sz = floor;
						sy = i;
						sx = j;
					}
					else if (tmp_input[j] == '#'){
						map[floor][i][j] = 0;
					}
					else if (tmp_input[j] == '.'){
						map[floor][i][j] = 1;
					}
				}
			}
			getline(cin, tmp_input);//개행 버리기
		}
		queue<tuple<int, int, int>> Q;
		Q.push({sx,sy,sz});
		vis[sz][sy][sx] = true;
		map[sz][sy][sx] = 1;
		while (!Q.empty()){
			auto t = Q.front();
			int tx = get<0>(t);
			int ty = get<1>(t);
			int tz = get<2>(t);
			Q.pop();
			int value = map[tz][ty][tx];
			if (tz == ez && ty == ey && tx == ex)
					break;
			vis[tz][ty][tx] = true;
			for(int i=0;i<6;i++){
				int mx = tx + dx[i];
				int my = ty + dy[i];
				int mz = tz + dz[i];
				if (mx <0 || my <0 || mz <0 || mx >= C || my >= R || mz >= L)
					continue;
				if (vis[mz][my][mx] == true || map[mz][my][mx] == 0)
					continue;
				map[mz][my][mx] = value+1;
				vis[mz][my][mx] = true;
				Q.push({mx,my,mz});
			}
		}
		if (map[ez][ey][ex] == 'E')
			cout << "Trapped!\n";
		else
			cout << "Escaped in "<<  map[ez][ey][ex] - 1<<" minute(s).\n";
		memset(vis, 0,sizeof(vis));
		memset(map,0, sizeof(map));
	}
}
