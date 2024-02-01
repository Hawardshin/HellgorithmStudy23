#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define CNT second
#define POS first
int N,K;
bool vis[100001];
int num_cnt[100001];
int min_cnt = 100001; //최소 거리

/* 5 17
5 10 20 19 18 17
5 6  7  8  16 17
5 6  7  8  9  18 17
5 10 9  18 17
5 10 9  8  16 17
5 4  8  16 17
*/
void	bfs(){
	queue<pair<int, int>> Q;
	Q.push({N,0});
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		// if (vis[q.POS])
		// 	continue;
		vis[q.POS] = true;
		if (q.POS == K)
		{
			min_cnt = min(q.CNT,min_cnt);
			num_cnt[q.CNT]++;
		}else {
			if (q.CNT > min_cnt)
				continue;
			if (q.POS<100000 && !vis[q.POS+1])
				Q.push({q.POS+1,q.CNT+1});
			if (q.POS>0 && !vis[q.POS-1])
				Q.push({q.POS-1,q.CNT+1});
			if ((q.POS)*2 <=100000 && !vis[(q.POS)*2])
				Q.push({q.POS*2,q.CNT+1});
		}
	}
}

int main(){
	cin >> N >> K;
	bfs();
	cout << min_cnt << "\n" << num_cnt[min_cnt] << "\n";
}