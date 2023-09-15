//최대 5번 이동이니까
//한번 이동할 때 4방향을 선택할 수 있고
//4^5번을 반복하면 모든 경우를 다 돌려볼 수 있다.
//2^10번이고 이건 2048번만을 하면 가능하기에 결국 브루스포스가 적합해보인다.
#include <iostream>
#include <vector>
#include <algorithm>
#define TABLESIZE 20
#define ll long long
using namespace std;
int table[TABLESIZE][TABLESIZE];
int next_table[TABLESIZE][TABLESIZE];
ll max_s;
int N;
/*
3
2 2 2
4 4 4
8 8 8
A : 16

3
1 1 1
0 0 0
1 1 1

3
1 1 1
1 1 1
1 1 1 
*/
void	printMap(){
	cout << "-----------------\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<< table[i][j];
		cout << "\n";
	}
}


void	MoveUp(){
	for(int i=0; i<N;i++){
		//0번 열부터 쭉 탐색
		for(int j=0;j<N;j++){ //i열 0행에 들어올 숫자 구하기
			int same = -1;
			if (table[j][i] != 0)
				same=table[j][i];
			for(int k=1;k+j<N;k++){
				if (table[j+k][i]==0)
					continue;
				if (same == -1){
					table[j][i] = table[j+k][i];
					table[j+k][i] = 0;
					same = table[j][i];
				}else{
					if (same == table[j+k][i]){
						table[j][i] += table[j+k][i];
						table[j+k][i] = 0;
					}
					break;
				}
			}
		}
	}
}

void	MoveDown(){
	for(int i=0; i<N;i++){
		//0번 열부터 쭉 탐색
		for(int j=N-1;j>0;j--){ //i열 0행에 들어올 숫자 구하기
			int same = -1;
			if (table[j][i] != 0)
				same=table[j][i];
			for(int k=1;j-k >= 0 ;k++){
				if (table[j-k][i]==0)
					continue;
				if (same == -1){
					table[j][i] = table[j-k][i];
					table[j-k][i] = 0;
					same = table[j][i];
				}else{
					if (same == table[j-k][i]){
						table[j][i] += table[j-k][i];
						table[j-k][i] = 0;
					}
					break;
				}
			}
		}
	}
}


void	MoveRight(){
	for(int i=0; i<N;i++){
		//0번 열부터 쭉 탐색
		for(int j=N-1;j>0;j--){ //i열 0행에 들어올 숫자 구하기
			int same = -1;
			if (table[i][j] != 0)
				same=table[i][j];
			for(int k=1;j-k>=0;k++){
				if (table[i][j-k]==0)
					continue;
				if (same == -1){
					table[i][j] = table[i][j-k];
					table[i][j-k] = 0;
					same = table[i][j];
				}else{
					if (same == table[i][j-k]){
						table[i][j] += table[i][j-k];
						table[i][j-k] = 0;
					}
					break;
				}
			}
		}
	}
}
void	MoveLeft(){
	for(int i=0; i<N;i++){
		//0번 열부터 쭉 탐색
		for(int j=0;j<N;j++){ //i열 0행에 들어올 숫자 구하기
			int same = -1;
			if (table[i][j] != 0)
				same=table[i][j];
			for(int k=1;k+j<N;k++){
				if (table[i][j+k]==0)
					continue;
				if (same == -1){
					table[i][j] = table[i][j+k];
					table[i][j+k] = 0;
					same = table[i][j];
				}else{
					if (same == table[i][j+k]){
						table[i][j] += table[i][j+k];
						table[i][j+k] = 0;
					}
					break;
				}
			}
		}
	}
}

void backTracking(int depth){
	int bef_map[21][21];
	for(int i=0;i <N;i++){
		for(int j=0;j<N;j++){
			if (max_s < table[i][j])
				max_s = table[i][j];
			bef_map[i][j] = table[i][j];
		}
	}
	if (depth == 5){
		return ;
	}
	MoveUp();
	backTracking(depth+1);
	for(int i=0;i <N;i++){
		for(int j=0;j<N;j++){
			table[i][j] = bef_map[i][j];
		}
	}
	MoveDown();
	backTracking(depth+1);
	for(int i=0;i <N;i++){
		for(int j=0;j<N;j++){
			table[i][j] = bef_map[i][j];
		}
	}
	MoveLeft();
	backTracking(depth+1);
	for(int i=0;i <N;i++){
		for(int j=0;j<N;j++){
			table[i][j] = bef_map[i][j];
		}
	}
	MoveRight();
	backTracking(depth+1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin >> table[i][j];
	}
	backTracking(0);
	// MoveRight();
	// printMap();
	// MoveDown();
	// printMap();
	// MoveUp();
	// printMap();
	// MoveUp();
	// printMap();
	// MoveLeft();
	// printMap();
	cout << max_s << "\n";
}