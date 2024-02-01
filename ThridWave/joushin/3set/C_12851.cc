#include <iostream>
#include <algorithm>

using namespace std;

int N,K;
bool vis[100001];
int num_cnt[100001];
int min_cnt = 100001;

void	bfs(int pos,int cnt){
	if (pos == K){
		min_cnt = min(min_cnt,cnt);
		num_cnt[cnt]++;
			vis[pos]= true;
	}
	else{
		if (vis[pos] == true)
			return ;
		vis[pos]= true;
		if (pos<100000)
			bfs(pos+1,cnt+1);
		if (pos>0)
			bfs(pos-1,cnt+1);
		if (pos*2 <=100000)
			bfs(pos*2,cnt+1);
	}
}

int main(){
	cin >> N >> K;
	bfs(N,0);
	cout << min_cnt << "\n" << num_cnt[min_cnt] << "\n";
}