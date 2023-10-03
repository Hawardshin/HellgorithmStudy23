#include <iostream>
/*
극장에서 지정석이 아닌 연속된 자리들은 바꿀수 있는 경우의 수가 이미 정해져있다.
즉 지정석이 아닌 연속된 자리들로 나오는 경우의 수들끼리의 곱이 정답이다.
1 2 3 4 5 6 7 8 9 10
X X O X X X X O X X

1 2 3 4 5 6 7 8 9
      x     x
*/
using namespace std;
int DP[41];
int N,M;

int main(){
	cin >> N;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for(int i=3;i<=N;i++){
		DP[i] = DP[i-1] + DP[i-2];
	}
	int tnum;
	int bef = 1;
	long long ret = 1;
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> tnum;
		if (tnum - bef > 0)
			ret *= DP[tnum - bef];
		bef = tnum +1;
		// cout << "?" << ret << "\n";
	}
	if (bef < N+1)
		ret*= DP[N-bef + 1];
	cout << ret<< "\n";
}
