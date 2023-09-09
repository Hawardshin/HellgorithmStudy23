#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,res=0,tab[100005]={0,},vis[100005]={0,},check[100005]={0,};

void dfs(int x){

    vis[x] = true;
	int next = tab[x];

	
	if (!vis[next]) {
		dfs( next);
	}
	else if (!check[next]) {//방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
		//자기 자신을 포함한 팀의 멤버를 카운트
		for (int i = next; i != x; i = tab[i]) {
			res++;
		}
		res++;
	}
	check[x] = true;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin>>t;

    while (t--){
        res = 0;
        memset(tab, false, sizeof(tab));
		memset(vis, false, sizeof(vis));
        memset(check, false, sizeof(check));
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>tab[i];
        
        for(int i=1; i<=n; i++){
            if (vis[i]) continue;
            dfs(i);
        }
        cout<<n-res<<"\n";
    }

    return 0;
}
