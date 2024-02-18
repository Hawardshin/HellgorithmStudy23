#include <iostream>
#include <algorithm>
#include <cstring>
#define IDX first
#define SIZE second
//1
using namespace std;

typedef struct s_shark{
	bool isDead;
	int x;
	int y;
	int speed;
	int size;
	int dir; //상하우좌 0,1,2,3
}t_shark;

t_shark shark[10001];
int R,C,M;
pair<int,int> shark_num[101][101];//해당위치에 상어가 현재 몇번째 인덱스 상어인지, 해당 상어의 크기

void printShark(){
	for(int i=0;i<M;i++){
		if (shark[i].isDead)
			cout << (char)('A' +i)  <<": 사망"<<"\n";
		else 
			cout << (char)('A' + i) << ": ("<< shark[i].x << ","<< shark[i].y << ") | size: " << shark[i].size<<"\n";
	}
}

int killShark(int x){
	int idx = -1;
	int dist = 1000000;
	for(int i=0;i<M;i++){
		if (shark[i].isDead == true)
			continue;
		if (x == shark[i].x&& shark[i].y  < dist){
			dist = shark[i].y;
			idx = i;
		}
	}
	if (idx == -1)
		return 0;
	shark[idx].isDead = true;
	return shark[idx].size;
}

void MoveShark(){
	for(int i=0;i<M;i++){
		shark_num[shark[i].y][shark[i].x] = {-1,-1};
		if (shark[i].isDead == true)
			continue;
		if (shark[i].dir == 1 || shark[i].dir == 2){
			for(int j=0;j<shark[i].speed % ((R-1)*2) ;j++){
			if (shark[i].dir == 1){
				if (shark[i].y == 1){
					shark[i].dir = 2;
					shark[i].y++;
				}else
					shark[i].y--;
			}else if (shark[i].dir == 2){
				if (shark[i].y == R){
					shark[i].dir = 1;
					shark[i].y--;
				}else
					shark[i].y++;
			}
		}
		}
		else {
			for(int j=0;j<shark[i].speed % ((C-1)*2) ;j++){
				 if (shark[i].dir == 3){
						if (shark[i].x == C){
							shark[i].dir = 4;
							shark[i].x--;
						}else
							shark[i].x++;
					}else if (shark[i].dir == 4){
						if (shark[i].x == 1){
							shark[i].dir = 3;
							shark[i].x++;
						}else
							shark[i].x--;
					}
				}
			}
	}
	for(int i=0;i<M;i++){
		if (shark[i].isDead)
			continue;
		if (shark_num[shark[i].y][shark[i].x].SIZE > shark[i].size){
			shark[i].isDead = true;
		}else {
			if (shark_num[shark[i].y][shark[i].x].IDX!= -1)
				shark[shark_num[shark[i].y][shark[i].x].IDX].isDead = true;
			shark_num[shark[i].y][shark[i].x] = {i,shark[i].size};
		}
	}
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> R>> C>> M;
	memset(shark_num,-1,sizeof(shark_num));
	for(int i=0;i<M;i++){
		cin >> shark[i].y >> shark[i].x >> shark[i].speed >> shark[i].dir >> shark[i].size ; 
	}
	int ret = 0;
	for(int x=1;x<=C;x++){
		ret += killShark(x);
		MoveShark();
	}
	cout << ret << "\n";
}