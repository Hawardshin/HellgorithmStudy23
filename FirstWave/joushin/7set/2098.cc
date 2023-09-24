#include <iostream>
#include <cstring>
#define InF 987654321
//걍 답지임 하,,, 이해했다고 할 수 있나..
using namespace std;

int n, answer_bit;

int table[16][16];
int cost[16][1<<16];
void	Input(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin >> table[i][j];
	}
	answer_bit = (1 << n) -1;
}

int dfs(int cur_node, int cur_bit){
	if (cur_bit == answer_bit){
		if (table[cur_node][0] == 0) return InF;
		else return table[cur_node][0];//처음으로 돌아가는 비용
	}
	if (cost[cur_node][cur_bit] != -1) return cost[cur_node][cur_bit];//이전에 왔던 곳을 또 온셈이니까 이전에 구했던 최솟값을 리턴한다.
	 cost[cur_node][cur_bit] = InF;//가장 뒤의 값을 가장 작게 하기 위해서 현재위치에 아주 큰 값을 넣어주는 것
	 for (int i = 0; i < n; i++){
		if (table[cur_node][i] == 0) continue;//이동 불가
		if ((cur_bit & (1 << i))  == (1 << i)) continue; //이미 방문학곳 이동 불가
		cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit], table[cur_node][i] + dfs(i, cur_bit | 1 << i));//현재 위치는 아주 큰 값과 dfs해서 나온 값과 현재 이동하는 거리의 합을 비교해서 최소값을 구하는 것 이기 때문에 현재 위치에서 다음 리턴값의 합을 게속해서 더해줘서 넣엊누다고 보면 된다.
	 }
	return cost[cur_node][cur_bit];//그렇게 구한 최소값을 리턴해준다.
}

void Solution(){
	memset(cost,-1,sizeof(cost));
	cout << dfs(0,1) <<"\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Input();
	Solution();
}



/*
[2]
[1,2]

[2,1]

[3]
[1,2,3] (1,3)
[1,3,2] (1,2)
[3,1,2] (3,2)

[2,1,3] (2,3)
[2,3,1] (2,1)
[3,2,1] (3,1)

[4]
[1,2,3,4] (1,4)
[1,2,4,3] (1,3)
[1,4,2,3] (1,3)
[4,1,2,3] (4,3)

[1,3,2,4] (1,4)
[1,3,4,2] (1,2)
[1,4,3,2] (1,2)
[4,1,3,2] (4,2)

[3,1,2,4] (3,4)
[3,1,4,2] (3,2)
[3,4,1,2] (3,2)
[4,3,1,2] (4,2)

[2,1,3,4] (2,4)
[2,1,4,3] (2,3)
[2,4,1,3] (2,3)
[4,2,1,3] (4,3)

[2,3,1,4] (2,4)
[2,3,4,1] (2,1)
[2,4,3,1] (2,1)
[4,2,3,1] (4,1)

[3,2,1,4] (3,4)
[3,2,4,1] (3,1)
[3,4,2,1] (3,1)
[4,3,2,1] (4,1)

*/