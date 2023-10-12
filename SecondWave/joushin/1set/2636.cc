#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int n,m;
#define X second
#define Y first
/*
입력 ->
변경 맵과 이전 백업맵 2개로 생김
이전 백업맵에서 bfs를 하는데 4방향 탐색중 0이 있다면 그 부분의
변경맵을 0으로 변경
그렇게 쭉 한바퀴를 다 돌고 나면 변경 맵을 검사해서 전부다 0인지 확인
전부다 0이면 이전 백업을 출력
아니라면 백업을 바꾼 맵으로 바꾸고
다시 함수 시작.
*/

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};


bool check_done(vector<vector<int>> ar){
	for (int i=0;i < n;i++){
		for (int j=0; j < m;j++){
			if (ar[i][j] != 0)
				return(true);
		}
	}
	return (false);
}

void	print(vector<vector<int>> ar){
	int cnt = 0;
	for(int i=0; i < n; i++){
		for (int j=0;j < m;j++){
			if (ar[i][j] ==1)
				cnt++;
		}
	}
	cout << cnt <<"\n";
}

void	map(vector<vector<int>> &arr){
	vector<vector<int>> change = arr;
	queue<pair<int,int>> Q;
	int cnt =0;
	while (check_done(change)){
		vector vis(n,vector<int>(m,0));
		arr = change;
		vis[0][0] = 1;
		Q.push({0,0});
		while (!Q.empty()){
			auto it = Q.front();
			Q.pop();
			for (int k=0;k < 4;k++){
				if (it.X +dx[k] < 0 || it.Y + dy[k]<0 ||it.X +dx[k] >=m || it.Y + dy[k] >= n)
					continue;
				if (vis[it.Y + dy[k]][it.X +dx[k]] == 1)
					continue;
				if (arr[it.Y + dy[k]][it.X +dx[k]] == 1){
					change[it.Y+dy[k]][it.X+dx[k]] = false;
					continue;
				}
				vis[it.Y + dy[k]][it.X +dx[k]]=true;
				Q.push({it.Y+ dy[k], it.X+dx[k]});
			}
		}
		cnt++;
	}
	cout << cnt << "\n";
	print(arr);
}




int main()
{
	cin >> n >> m;
	vector arr(n,vector<int>(m,0));
	for (int i=0;i<n;i++){
		for(int j=0;j <m;j++){
			cin >>arr[i][j];
		}
	}
	//모든 지도 돈다.
	map(arr);
}

