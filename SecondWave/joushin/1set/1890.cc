#include <iostream>
//우측으로 이동 -> 반복
//한칸 내리고 가능하면 우측으로 이동 반복
//전칸에서 전부 아래로 이동
//
/*
1 1 1
1 1 1
1 1 0

0 0 0
0 0 0
0 0 0

0 1 1
1 0 0
1 0 0

0 1 1
1 2 3
1 3 6


1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 0

0 0 0 0 
0 0 0 0
0 0 0 0
0 0 0 0

0 1 1 1
1 0 0 0
1 0 0 0
1 0 0 0

0 1 1 1
1 2 2 2
1 2 2 2
1 2 2 2

0 1 1 1
1 2 
*/

/*
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

0 0 1 0
0 0 0 0
1 0 0 0
1 0 0 0

0 0 1 0
0 0 0 0
1 1 0 0
1 0 0 0

0 0 1 0
0 0 0 0 
1 1 0 0
1 0 1 0

0 0 1 0
0 0 0 0
1 1 0 1
1 0 1 3



*/
using namespace std;

int N;
int table[101][101];
int ret[101][101];

void printTab(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << ret[i][j];
		}
		cout << "\n";
	}
	cout << "--------------------------\n\n";
}


void make_row(int i){
	cout << i << "번째 줄" << "\n";
	for(int j=0; i+j < N;j++){
		for(int x=0;x< i+j;x++)
			if (table[i][x] + x == i+j){
				if (i == 0 && ret[i][x]==0)
				{
					ret[i][i + j]=1;
				}
				else 
					ret[i][i + j]+= ret[i][x];
			}
		for(int k=0;k<i;k++){
			if (i == k+ table[k][i+j])
				ret[i][i+j] += ret[k][i+j];
		}
	}
}

void make_col(int i){//
	for(int j=0; i+j < N;j++){
		for(int x=0;x< i+j;x++){
			if (table[x][i] + x == i+j){
				if (i == 0 && ret[x][i]==0)
				{
					ret[i + j][i]=1;
				}else 
					ret[i + j][i] += ret[x][i];
			}
		}
		// for(int k=0;k<i;k++){
		// 	if (i == k+ table[i+j][k])
		// 		ret[i + j][i] += ret[i+j][k];
		// }
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> table[i][j];
		}
	}
	for(int i=0;i<N;i++){
		make_row(i);// i번째 줄 가로 y=i부터 업데이트
		printTab();
		make_col(i);//i번쨰 줄 세로 x=i부터 업데이트 
		printTab();
	}
	cout << ret[N-1][N-1]<<"\n";
}