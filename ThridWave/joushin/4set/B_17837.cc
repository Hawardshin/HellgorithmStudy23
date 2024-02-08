/*
	N*N 체스판 
	사용말 : K개 
	각칸 : 흰빨파
		-흰색 : 바로이동
		-빨간색 : 이동 후 쌓여있는 순서 변경
		-파란색 : 말의 이동방향 반대로 설정 후 한칸 이동 (파란색, 바깥은 안나감)
	말위에 다른말 가능, 이동방향 4개

	말 4개 쌓이는 순간 종료
	
	체스판 크기 : N
	말의 갯수 : K
	체스판 정보 0->흰색, 1->빨, 2->파
	말 : 행, 열, 이동방향
	-> <- up down
	나보다 늦게 온 녀석들 숫자 저장
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct s_point{
	int num;
	int dir;
}t_point;

vector<t_point>p_table[11][11];
int table[11][11];
int N,K;
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cin >> table[i][j];
	}
	for(int i=0;i<K;i++){
		int y;int x; int dir;
		cin >> y >>x>> dir;
		
	}
}
