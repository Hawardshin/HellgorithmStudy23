#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N; //화단 한변의 길이
//0~N-1까지
//N~ 2N-1까지
//abs(b-a) == (N || N-1 || N+1)
int table[201][201];
int least_money = 2147483647;

int money_cnt(int x1,int y1){
	int cnt = 0;
	cnt +=table[y1][x1];
	cnt+= table[y1+1][x1];
	cnt+= table[y1-1][x1];
	cnt+= table[y1][x1-1];
	cnt+= table[y1][x1+1];
	return (cnt);
}

void make_three_flower(int a,int b,int c){
	int aMb = abs(b-a);
	int bMc = abs(b-c);
	int aMc = abs(a-c);
	if (aMb <=2 ||bMc <= 2 || aMc <=2)
		return ;
	if (a %N == 0 || a % N == N-1 || b % N == 0 || b % N == N-1 || c % N == 0 || c % N == N-1)
		return ;
	if ((N-1 <=bMc && bMc <= N+1 ) || (N-1 <=aMb && aMb <= N+1 ) || (N-1 <=aMc && aMc <= N+1 ))
		return ;
	if (aMb == 2*N || aMc == 2*N || bMc == 2*N)
		return ;
	int x1 = a%N;
	int y1 = a/N;
	int	x2 = b%N;
	int y2 = b/N;
	int x3 = c%N;
	int y3 = c/N;
	int cnt = 0;
	if (y1 == N-1 || y2 == N-1 || y3 == N-1 || x1 == N-1 || x2 == N-1 || x3 == N-1 || x1 == 0 || x2 == 0 || x3 == 0 || y1 == 0 || y2 == 0 || y3 == 0)
		return ;
	cnt+= money_cnt(x1,y1);
	cnt+= money_cnt(x2,y2);
	cnt+= money_cnt(x3,y3);
	if (cnt < least_money)
		least_money = cnt;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> table[i][j];
		}
	}
	int max_N = N*N -1;
	for(int i=0;i<max_N;i++){
		for(int j=i+1;j<max_N;j++){
			for(int k=j+1;k< max_N;k++){
				make_three_flower(i,j,k);
			}
		}
	}
	cout << least_money<< "\n";	
}