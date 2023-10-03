/*
타일은 크게 2가지 종류의 경우로 나눌 수 있다.
1. 가로의 길이가 2가 되는 경우
2. 가로의 길이가 6이 되는 경우
다만 1이 연속해서 3개가 되는 경우 길이가 6이 될 수 있긴 하지만 둘은 다른 경우의 수로 본다.(눕혀진 타일이 2개 있는 경우에 해당)
1. 2가 되는 경우 ->2개 
2. 3이 되는 경우->1개
3. 6이 되는 경우 -> 2개

DP[1]=0
DP[2]=2
DP[3]=1
DP[4]=DP[2]*DP[2]
DP[5]=DP[2]*DP[3]
DP[6]=DP[2]*DP[4]
DP[7]=(DP[2]*DP[5])+(DP[3]*DP[4])
DP[8]=DP[2]*DP[6] + DP[3]*DP[5] + DP[4]*DP[4]
*/

#include <iostream>

using namespace std;
int n;
int DP[31]={0,0,2,1,4,3,11,};
int main(){
	cin >> n;
	for(int i=0;i<=n;i++){
		DP[] = 
	}
}