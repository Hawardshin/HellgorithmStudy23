/*
N*N 체스판
K : 말의 갯수
0: 흰색
1: 빨강
2: 파랑

1. 입력을 받는다.
2. 각 점별로 스택을 둔다.
3. 이동하고자 할 때 : 
	- 다음칸 흰색 : 그낭 이동
	- 다음칸 파랑 : 방향 변경 및 한칸 이동 (단 다음칸이 낭떠러지거나 파랑이면 방향만 변경)
	- 다음칸 빨강 : 일단 이동 후 Stack을 뒤집음
- 빨강이 아닌경우
	이동할 때 stack을 pop해서 이동하려는 숫자가 나올 때까지 tmp에 쌓고, tmp를 다시 이동하려는 stack에 push
- 빨강인 경우
	이동할 때 이동하려는 stack을 전부 pop 해서 tmp에 넣고 이동하려는 stack에 pop해가면서 값을 넣고 이후 tmp를 넣는다.
	인줄 알았는데 tmp에 넣는걸 다시 뒤집어야만한다.
 
종료조건 : 해당 stack의 크기가 4가 되는 순간 종료 또는 날짜가 1000이 넘는경우

구현 전략 : 흰색 구현 후 test, 파랑 구현 후 test, 이후 빨강 구현	
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#define WHITE 0
#define RED 1
#define BLUE 2

 enum e_dir{
	STOP,
	RIGHT,
	LEFT,
	UP,
	DOWN
};

int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

typedef struct s_horse{
	int x;
	int y;
	int dir;
} t_horse;

using namespace std;


int N,K;
int table[11][11];
t_horse horseStore[11];
stack<int> parking[11][11];


void print_parking(){
	cout << "---------------------\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << parking[i][j].size();
		}
		cout << "\n";
	}
}

void input(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cin >> table[i][j];
	}
	for(int i=1;i<=K;i++){
		int x,y,dir;
		cin >> y>>x >> dir;
		horseStore[i] = {x,y,dir};
		parking[y][x].push(i);
	}
}

e_dir reverseDir(int dir){
	switch(dir){
		case LEFT : 
			return RIGHT;
		case RIGHT: 
			return LEFT;
		case UP:
			return DOWN;
		case DOWN: 
			return UP;
	}
	return STOP;
}

void updateStack(bool isRed,int now_horse, int nx,int ny,int x,int y){
	deque<int> tmp;
	if (isRed){
		int nHorse = -1;
		while (nHorse != now_horse){
			nHorse = parking[y][x].top();
			// cout << "주차중인 말 : " <<  nHorse << "\n";
			parking[y][x].pop();
			horseStore[nHorse].x = nx;
			horseStore[nHorse].y = ny;
			parking[ny][nx].push(nHorse);
		}
	}else {
		int nHorse = -1;
		while (nHorse != now_horse){
			nHorse = parking[y][x].top();
			// cout << "주차중인 말 : " <<  nHorse << "\n";
			parking[y][x].pop();
			horseStore[nHorse].x = nx;
			horseStore[nHorse].y = ny;
			tmp.push_back(nHorse);
		}
		while (!tmp.empty()){
			parking[ny][nx].push(tmp.back());
			tmp.pop_back();
		}
	}
}

bool moveNext(int horse, int x,int y,int dir){
	int nx = x+dx[dir];
	int ny = y+dy[dir];

	stack<int>tmp;
	bool isRed = false;
	if (nx < 1 || ny < 1 || nx > N || ny> N || table[ny][nx] == BLUE){
		// cout << "다음칸 낭떠러지나 블루\n";
		dir = reverseDir(dir);
		nx = x+dx[dir];
		ny = y+dy[dir];
		horseStore[horse].dir=dir;
		if (nx < 1 || ny < 1 || nx > N || ny> N || table[ny][nx] == BLUE){
			if (parking[y][x].size() >=4 )
				return true;
			return false;
		}
	}
	if (table[ny][nx] == RED){
		// cout << "다음칸 빨강\n";
		isRed = true;
	}
	// cout << "다음위치: " << nx<< ny << "\n";
	updateStack(isRed,horse,nx,ny,x,y);
	if (parking[ny][nx].size() >=4 )
		return true;
	return false;
}

int main(){
	input();
	int day = 1;
	while (day<=1001){
		// cout << "시작!\n";
		// print_parking();
		for(int i=1;i<=K;i++){
			// cout << i <<"번 말 : " <<horseStore[i].x << "," << horseStore[i].y << "\n" ;
			if (moveNext(i,horseStore[i].x,horseStore[i].y,horseStore[i].dir)){
				cout << day<<"\n";
				return 0;
			}
			// print_parking();
		}
		// cout << "--------day: " << day << "-----------\n";
		day++;
	}
	cout << -1 << "\n";
}