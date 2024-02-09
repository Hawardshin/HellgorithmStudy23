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
#include <cmath>
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

int main(){
	cin >> a_goal >> b_goal;
	initPaskal();
	a_goal /= 100; b_goal /=100;
	double notSa =0;
	double notSb =0;
	for(int r: not_sosu){
		notSa+= C[r]*pow(a_goal,r)* pow(1-a_goal,18-r);
		notSb+= C[r]*pow(b_goal,r)*pow(1-b_goal,18-r);
	}
	cout << 1 - notSa * notSb << "\n";
}