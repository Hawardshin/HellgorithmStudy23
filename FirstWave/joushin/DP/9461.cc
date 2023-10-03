/*
두 변의 합으로 새로운 삼각형을 만든다.
1,
1,
1
1+1 ->2
1+1->2
1+2->3
3+1->4
4+1->5
5+2->7
7+2->9
9+3->12
12+4->16

DP[x] = DP[x-1] + DP[x-5];
*/

#include <iostream>

using namespace std;
long long DP[101]={0,1,1,1,2,2,3,4,5,7,9,0,};
int main(){
	int t;
	cin >> t;
	for(int i=9;i<=100;i++){
		DP[i] = DP[i-1] + DP[i-5];
	}
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		cout << DP[n] << "\n";
	}
}