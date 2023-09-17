#include <iostream>
#include <queue>
#include <cstring>
#define MAX_MAP 51
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int R,C,T;
long long dust_sum;
int input[MAX_MAP][MAX_MAP];
int next_input[MAX_MAP][MAX_MAP];
int clean_idx;
void print_Input(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << input[i][j];
		}
		cout << "\n";
	}
	cout << "------------\n";
}

void SpreadDust(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)	
			next_input[i][j] = input[i][j];
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if (input[i][j] > 0){
				int move_sum = 0;
				for(int k=0;k<4;k++){
					int tx =j+dx[k];
					int ty =i+dy[k];
					if (tx <0 || ty <0 || tx >=C ||ty>=R)
						continue;
					if (input[ty][tx] < 0)
						continue;
					move_sum+= (input[i][j] /5);
					next_input[ty][tx] = next_input[ty][tx] +(input[i][j] /5);
				}
				next_input[i][j] = next_input[i][j] - move_sum;
			}
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if (input[i][j] !=-1){
				input[i][j] = next_input[i][j];
			}
		}
	}
	memset(next_input,0,sizeof(next_input));
}
void	Cleaning(){
	int up_idx = clean_idx -1;
	dust_sum -= input[up_idx-1][0];
	// cout <<"aa" <<up_idx <<input[up_idx -1][0]<<"\n";
	for(int i = up_idx - 1; i > 0;i--)
		input[i][0] = input[i - 1][0];
	for(int i=0;i <C - 1;i++)
		input[0][i] = input[0][i+1];
	for(int i=0;i <= up_idx;i++)
		input[i][C-1] = input[i+1][C-1];
	for(int i=C-1;i >1; i--)
		input[up_idx][i] = input[up_idx][i - 1];
	input[up_idx][1] = 0;
	int down_idx = clean_idx;
//아래쪽 가동

	dust_sum-= input[down_idx +1][0];
	for(int i=down_idx +1; i < R - 1;i++)
		input[i][0] = input[i+1][0];
	for(int i=0;i <C-1;i++)
		input[R - 1][i] = input[R-1][i+1];
	for(int i=R-1;i > down_idx;i--)
		input[i][C-1] = input[i-1][C-1];
	for(int i= C-1; i >1;i--)
		input[down_idx][i] = input[down_idx][i-1];
	input[down_idx][1] = 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> R>>C >>T;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++) {
			cin >> input[i][j];
			if (input[i][j] >0)
				dust_sum+= input[i][j];
			else if (input[i][j] == -1)
				clean_idx = i;//아래쪽 공기청정기 인덱스가 된다.
		}
	}
	// print_Input();
	for(int i=0;i<T;i++){
		SpreadDust();
		// print_Input();
		Cleaning();
		// print_Input();`
	}
	cout << dust_sum << "\n";
}