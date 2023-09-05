#include <iostream>
#include <cstring>
using namespace std;

int T,n;
int student_link[100001];
bool vis[100001];
bool done[100001];
#define IMPOSSIBLE  -1
#define DONE 0
	int ret = 0;
void make_ret(int now){
	vis[now] = true;
	int next = student_link[now];
	if (!vis[next])
		make_ret(next);
	else if (!done[next]){//한번 방문했던 노드지만 아직 안 끝난경우
		for(int i=next; i!=now; i = student_link[i])
			ret++;
		ret++;
	}
	done[now] =true;
}


void solve(){
	ret = 0;
	memset(vis, false, sizeof(vis));
	memset(done, false, sizeof(done));
	for(int i=1; i <= n;i++){
		if (vis[i] == false)
			make_ret(i);
	}
	cout<<n - ret<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T ;
	for(int i=0;i < T;i++){
		cin >> n;
		for(int j=1;j <=n; j++){
			cin >> student_link[j];	
		}
		solve();
	}
}