/*
총 가능한 빙고의 갯수는 12개고
가로 [0]0~4, 새로[1] 0~4,대각선[2] 0~1로 합니다.
0,0 의 경우 -> [0]0,[1]0, [2]0
0,4 -> [0]0, [1]4, [2]1
4,0 -> [0]4, [1]0, [2]1
4,4 -> [0]4, [1]4, [2]1
즉  y,x 의 인덱스의 숫자를 만나면 
y -> [0][y]++;
x -> [1][x]++;
if (x+y == 4)
	[2][1]++;
if (x == y)
	[2][0]++;
*/
#include <iostream>
using namespace std;

pair<int,int>input[25]; //y,x
int DP[3][5];

int main(){
	int tmp;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> tmp;
			input[tmp] = {i,j};
		}
	}
	int ret = 0;
	int cnt = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> tmp;
			int y = input[tmp].first;
			int x = input[tmp].second;
			DP[0][y]++;
			DP[1][x]++;
			int plus_bingo =0;
			if (x+y == 4){
				DP[2][1]++;
				if (cnt<3 && DP[2][1] == 5){
					plus_bingo++;
					ret = ((i*5)+j+1);
				}
			}
			if (x == y){
				DP[2][0]++;
				if (cnt<3 && DP[2][0] == 5){
					plus_bingo++;
					ret = ((i*5)+j+1);
				}
			}
			if (cnt<3 &&DP[0][y] == 5){
				plus_bingo++;
				ret = ((i*5)+j+1);
			}
			if (cnt<3&& DP[1][x] == 5){
				plus_bingo++;
				ret = ((i*5)+j+1);
			}
			cnt += plus_bingo;
		}
	}
	cout << ret<< "\n";
}
