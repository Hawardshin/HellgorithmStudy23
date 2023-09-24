//가로인 경우 : (0,1), (1,1)
//세로인 경우 : (1,0), (1,1)
//대각선인 경우 (0,1) (1,0) (1,1)
//1,1로 이동하는 경우 (1,0),(0,1) 모두 벽이 아니어야만 함.
#include <iostream>
#include <algorithm>
#define TABLE_MAX 17
#define DIRECTION 3
using namespace std;
int table[TABLE_MAX][TABLE_MAX];
int DP[DIRECTION][TABLE_MAX][TABLE_MAX];//가로, 세로, 대각선

int N;

void updataDp(int y, int x){
	if (table[y][x] == 1)
		return;
	if (table[y][x-1] != 1){
		DP[0][y][x] += DP[0][y][x-1];
		DP[0][y][x] += DP[2][y][x-1];
	}
	if (table[y-1][x] != 1){
		DP[1][y][x] += DP[1][y-1][x];
		DP[1][y][x] += DP[2][y-1][x];
	}
	if (table[y-1][x-1] != 1 && table[y][x-1] != 1 && table[y-1][x] != 1){
		DP[2][y][x] += DP[0][y-1][x-1];
		DP[2][y][x] += DP[1][y-1][x-1];
		DP[2][y][x] += DP[2][y-1][x-1];
	}
}

int main(){
	cin >> N;
	int tmp;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> table[i][j];
		}
	}
	for(int i=2;i<=N;i++){
		if (table[1][i-1])
			break;
		DP[0][1][i] = 1;
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			updataDp(i,j);
		}
	}
	cout << DP[0][N][N] + DP[1][N][N] + DP[2][N][N] << "\n";
}
