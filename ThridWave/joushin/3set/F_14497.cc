/*
주난 : *
초코바 : #
빈칸 : .
1: 친구

bfs해서 닿은 1은 다 녹이면된다.
처음으로 #에 다은 경우 끝
*/
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool vis[301][301];
char table[301][301];
int N,M;

int main(){
	int x1,y1,x2,y2;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	cin >> y1 >> x1 >> y2>>x2;
	y1--; x1--; y2--; x2--;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin >> table[i][j];
	}
	queue<pair<int,int>>Q[2];
	Q[0].push({x1,y1});
	int day =0;
	while (true){
		while (!Q[day%2].empty()){
			auto q = Q[day%2].front();
			Q[day%2].pop();
			for(int i=0;i<4;i++){
				int nx = dx[i]+q.X;
				int ny = dy[i]+q.Y;
				if (nx < 0 || ny < 0 || nx>=M || ny>=N)
					continue;
				if (vis[ny][nx] == true)
					continue;
				vis[ny][nx] = true;
				switch(table[ny][nx])
				{
					case '0' : 
						Q[day%2].push({nx,ny});
						break;
					case '1':
						Q[(day+1)%2].push({nx,ny});
						table[ny][nx] = '0';
						break;
					case '#': 
						cout << day+1<<"\n";
						return 0;
				}
			}
		}
		day++;
	}
}