//1~20 2->40
//13,16,19 : 21~23
//22,24 : 24~25
//28,27,26 : 26~28
//25,30,35: 29~31
//도착지점 : 인덱스 32

//5에서 출발 -> 21로 이동
//23에도달 : 29로 이동
//10에서 출발 -> 24로이동
//25에 도달 -> 29로이동
//15에서 출발 -> 26으로 이동
//31에 도달-> 20
//20에 도달 -> 32로 이동
//그외는 다 한칸씩 앞으로 이동

// 시간 복잡도 :  4^10이므로

//이동한 곳의 점수를 알려줌.
//만약 이동할 곳이 다른 말이 있다면, 해당 위치는 이동할 수 없으므로 -1 반환.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int dice[10];
int table[33] ={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,28,27,26,25,30,35,0};
int horse[4]; //모두의 시작점 0
int maxP = 0;

int moveNext(int toMove, int start,int hNum){
	int now = start;
	if (start == 5){
		toMove--;
		now = 21;
	}
	else if (start == 10){
		toMove--;
		now = 24;
	}else if (start == 15){
		toMove--;
		now = 26;
	}

	while (toMove>0){
		if (now == 23){
			now = 29;
		}
		else if (now == 25){
			now = 29;
		}
		else if (now == 31){
			now = 20;
		}else if (now == 20){
			now = 32;
		}else if (now == 32) {
			break;
		}
		else {
			now++;
		}
		toMove--;
	}
	for(int i=0;i<4;i++){
		if (horse[i] != 32 && horse[i] == now)
			return -1;
	}
	horse[hNum] = now;
	return table[now];
}



void recur(int idx,int point){
	if (idx == 10){
		maxP = max(maxP,point);
		return ;
	}
	else {
		if (horse[0] != 32){
			int befPos = horse[0];
			int mCnt = moveNext(dice[idx],horse[0],0);
			if (mCnt != -1){
				recur(idx+1,point+mCnt);
				horse[0] = befPos;
			}
		}
		if (horse[1] != 32){
			int befPos = horse[1];
			int mCnt = moveNext(dice[idx],horse[1],1);
			if (mCnt != -1){
				recur(idx+1,point+mCnt);
				horse[1] = befPos;
			}
		}
		if (horse[2] != 32){
			int befPos = horse[2];
			int mCnt = moveNext(dice[idx],horse[2],2);
			if (mCnt != -1){
				recur(idx+1,point+mCnt);
				horse[2] = befPos;
			}
		}
		if (horse[3] != 32){
			int befPos = horse[3];
			int mCnt = moveNext(dice[idx],horse[3],3);
			if (mCnt != -1){
				recur(idx+1,point+mCnt);
				horse[3] = befPos;
			}
		}
	}
}

int main(){
	for(int i=0;i<10;i++){
		cin >>dice[i];
	}
	recur(0,0);
	cout << maxP<<"\n";
}
