/*
90분 ->5분 간격 
0-5 5-10 10-15 15-20 ... 85-90
최대 득점 수 : 90/5=18
소수 : 2,3,5,7,11,13,17 -> 7개
소수가 나올 확률 : 
	소수 소수 
	소수 안소수
	안소수 소수
	안소수 안소수
둘 다  소수가 아닌 경우를 모두 계산한 이후에 전체 확률을 빼주면 되지 않을까?
11*11 의 경우의 수가 존재
각  경우의 수에 따른 확률 계산하면 될듯..!

한팀이 한골만 얻을 확률
1. 16C1 * 승리확률^1 * 패배확률 ^15

...
한팀이 한골 넣을 확률 * 한팀 한골 넣을 확률 + 
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double a_goal;
double b_goal;

int not_sosu[12] = {0,1,4,6,8,9,10,12,14,15,16,18};
int C[19];

//18C0부터 18C 18까지.
void	initPaskal(){
	C[0] = C[1] = 1;
	for (int i=2;i<=18;i++){
		C[0]=C[i]=1;
		for(int j=i-1;j>0;j--){
			C[j] += C[j-1];
		}
	}
}

double winRate(int num,double win_rate){
	double ret = 1;
	for(int i=0;i<num;i++){
		ret*=win_rate;
	}
	for(int i=0;i<18-num;i++){
		ret*=(1 - win_rate);
	}

	//18Cnum
	ret*=C[num];
	return ret;
}

// 18Ca 18Cb
double calcPersent(int a,int b){
	return winRate(a, a_goal) * winRate(b, b_goal);
}

int main(){
	cin >> a_goal >> b_goal;
	initPaskal();
	a_goal /= 100; b_goal /=100;
	double not_sosu_rate =0;
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			not_sosu_rate += calcPersent(not_sosu[i],not_sosu[j]);
		}
	}
	cout << setprecision(18) << 1 - not_sosu_rate << "\n";
}