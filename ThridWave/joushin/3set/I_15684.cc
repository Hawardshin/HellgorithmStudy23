#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;
int N,H;//점선 가로, 점선 세로
int M;//놓인 가로
bool table[31][11]; // table[H][N-1]


int ret =  5;
int dp[31][11];
bool calcDp(){//초기 주어진 값으로 dp배열 계산
	// cout << "--------------첫 디피 결과!-----------------\n";
	for(int i=1;i<=N;i++)
		dp[0][i]=i;
	for(int i=1; i<=H; i++){
		for(int j=1;j<=N;j++){
			if (table[i][j]){//줄이 있는 경우 둘의 위치 교환
				int tmp = dp[i-1][j];
				dp[i][j] = dp[i-1][j+1];
				dp[i][j+1] = tmp;
				j++;
			}
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	for(int i=1;i<=N;i++){
		if (dp[H][i] != i)
			return false;
	}
 	return true;
}

void print_table(){
	cout << "---------------테이블 출력---------------\n";
	for(int i=1;i<=H;i++){
		for(int j=1;j<=N;j++)
			cout << table[i][j] << "|";
		cout << "\n";
	}
}

void dfs(int high ,int cnt){
	if (cnt > 3)
		return ;
	if (calcDp() == true)
	{
		ret = min(ret, cnt);
		return ;
	}
	for(int i=high;i<=H;i++){
		for(int j=1;j<N;j++){
			if (table[i][j] || table[i][j-1] || table[i][j+1]) continue;
			table[i][j] = true;
			dfs(i,cnt+1);
			table[i][j] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M >> H;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a>>b;
		table[a][b] = true;
	}
	dfs(1,0);
	if (ret == 5)
		ret = -1;
	cout << ret << "\n";

}
