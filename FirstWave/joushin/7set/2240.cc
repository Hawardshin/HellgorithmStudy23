//1의 나무에 있는경우
//2의 나무에 있는경우
//N번 이동할 수 있다는 제약
//이동할 때마다 달라지는 얻을 점수
//그리디도 생각해볼수도?
//시작할 때 1로 시작하기 때문에 앞부분이 1이면 다 먹는다.
//다음으로는 모든 배열에서 가장 큰 녀석들을 먹을 수 있게 이동시킨다.
//그 시간에 1에 있을때 몇개인지
//그 시간에 2에 위치해 있을 때 몇개이고 몇번이 남았는가
//1000초동안 이동할 때 1의 최대 최소 + 남은 이동횟수
// 생각전환 : 버린 자두의 갯수가 최소가 될 때 
#include <iostream>
#include <vector>
#include <algorithm>
#define JADUPOS 3
#define MAX_TIME 1002
#define MAX_MOVE 32
#define NowTree first
#define JaduSize second
using namespace std;
int DP[JADUPOS][MAX_TIME][MAX_MOVE];
//[0] 에는 현재 초에 1 위치에 있다면 몇개를 버린건지가 들어있다.
//[1] 에는 현재 초에 2 위치에 있다면 몇개를 버린건지가 저장됩니다.
//DP[0][T][M] = max(DP[0][T-1][M] ,DP[1][T-1][M-1])
//DP[1][T][M] = max(DP[0][T-1][M-1], DP[1][T-1][M])
//DP[0][0][M] = 먹은 자두의 수가 들어가고
//DP[0][1][M] =
int ret  =0;
int input[MAX_TIME];
int T,W;
vector<pair<int,int>>jadu;
int main(){
	cin >> T>>W;
	for(int i=1;i<=T;i++){
		cin >> input[i];
	}
	for (int i = 1; i <= T; i++) { //1초부터 T초까지
		for (int j = 1; j <= W + 1; j++) { //이동은 1번부터 W+1번까지 
			if (input[i] == 1) {
				DP[1][i][j] = max(DP[1][i - 1][j] + 1, DP[2][i - 1][j - 1] + 1);
				DP[2][i][j] = max(DP[1][i - 1][j - 1], DP[2][i - 1][j]);
	    } else {
	      if (i == 1 && j == 1) 
	        continue;
	      DP[1][i][j] = max(DP[2][i - 1][j - 1], DP[1][i - 1][j]);
	      DP[2][i][j] = max(DP[1][i - 1][j - 1] + 1, DP[2][i - 1][j] + 1);
	    }
	  }
	}
	int ans = 0;
	for (int i = 1; i <= W + 1; i++) {
      ans = max(ans, max(DP[1][T][i], DP[2][T][i]));
  }
	cout << ans <<"\n";
}
