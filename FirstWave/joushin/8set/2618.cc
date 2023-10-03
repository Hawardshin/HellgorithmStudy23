#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_EVENT 1001
#define y first
#define x second
using namespace std;
int n,w;//도로의 갯수, 사건의 갯수
int DP[MAX_EVENT][MAX_EVENT];
//DP[2][1] -> 1번 경찰차가 2번 사건을 맡고, 2번 경찰차가 1번 사건을 맡을 때 최소 거리
pair<int,int> in_evt[MAX_EVENT];//y,x
//입력으로 들어온 최대 이벤트 좌표

void Input(){
	cin >> n >> w;
	for(int i=1;i<=w;i++){
		int a,b;
		cin >> a>>b;
		in_evt[i]={a,b};
	}
	memset(DP, -1, sizeof(DP));
}


int calcDist(int nx,int ny, int tx,int ty){
	int mx = abs(nx-tx);
	int my = abs(ny-ty);
	return (mx + my);
}

int MakeDistance(int a,int b){//a자동차의 마지막 사건번호 b 자동차의 마지막 사건번호
	if (a== w || b == w)//둘 중 하나가 마지막 사건을 맡은 경우
		return(0);
	if (DP[a][b] != -1)//이전에 끝까지 갔던 적 있는 경우라면
		return (DP[a][b]);
	int nxt_evt = max(a,b) + 1; 
	int aDist,bDist;

	if (a == 0){
		aDist = calcDist(1,1,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}else{
		aDist = calcDist(in_evt[a].x,in_evt[a].y,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}
	if (b ==0){
		bDist = calcDist(n,n,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}else{
		bDist = calcDist(in_evt[b].x,in_evt[b].y,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}
	int aRet = aDist + MakeDistance(nxt_evt,b);
	int bRet = bDist + MakeDistance(a,nxt_evt);
	DP[a][b] = min(aRet,bRet);
	return (DP[a][b]);
}

void printPolice(int a,int b){
	if (a== w || b == w)//둘 중 하나가 마지막 사건을 맡은 경우
		return ;
	int nxt_evt = max(a,b) + 1; 
	int aDist,bDist;

	if (a == 0){
		aDist = calcDist(1,1,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}else{
		aDist = calcDist(in_evt[a].x,in_evt[a].y,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}
	if (b ==0){
		bDist = calcDist(n,n,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}else{
		bDist = calcDist(in_evt[b].x,in_evt[b].y,in_evt[nxt_evt].x,in_evt[nxt_evt].y);
	}
	if (DP[nxt_evt][b] + aDist < DP[a][nxt_evt] + bDist){
		cout << 1 << '\n';
		printPolice(nxt_evt,b);
	}else{
		cout << 2 << "\n";
		printPolice(a,nxt_evt);
	}
}

int main(){
	Input();
	cout << MakeDistance(0,0) << "\n";
	printPolice(0,0);
}
