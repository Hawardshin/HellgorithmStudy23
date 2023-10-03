//날씨 흐림
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>

#define MaxPlace 501
#define INF 50000000
using namespace std;
int n,m;//장소의 수, 도로의 수
int s,d;//시작점, 도착점
vector<pii> links[MaxPlace];//장소에 따른 링크
//value, 연결 노드
int Dist[MaxPlace];
vector<int> way[MaxPlace];
bool vis[MaxPlace];//bfs방문 표시


void dijkstra(){
	Dist[s] = 0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,s});
	while (!pq.empty()){
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (Dist[cur] < cost) continue;
		for(int i=0;i<links[cur].size();i++){
			int nxt = links[cur][i].first;
			int n_cost = links[cur][i].second;
			if (n_cost == -1)
				continue;
			if ( Dist[cur] + n_cost < Dist[nxt] ){
				Dist[nxt] = Dist[cur]+n_cost;
				way[nxt].clear();
				way[nxt].push_back(cur);
				pq.push({Dist[nxt],nxt});
			}else if (Dist[nxt] == Dist[cur] + n_cost){
				way[nxt].push_back(cur);
			}
		}
	}
}

void bfs(){
	queue<int> q;
	q.push(d);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (vis[x]) continue;
		vis[x] =true;
		for(int i=0;i<way[x].size();i++){
			int nx = way[x][i];
			for(int j=0;j<links[nx].size();j++){
				if (links[nx][j].first == x) links[nx][j].second = -1;//간선 삭제
				}
				q.push(nx);
		}
	}
}


bool input(){//끝났으면 return true
	cin >> n>>m;
	if (n ==0 && m ==0)
		return 1;
	cin >> s >> d;
	for(int i=0;i<m;i++){
		int u,v,p;//u->v 거리 p
		cin >> u>>v>>p;
		links[u].push_back({v,p});
	}
	return 0;
}

void init(){
	for(int i=0;i<MaxPlace;i++)
		Dist[i] = INF;
	memset(way,0,sizeof(way));
	memset(links,0,sizeof(links));
	memset(vis,false,sizeof(vis));
}

int main(){
	while (1){
		init();
		if (input())
			return 0;
		dijkstra();//start부터 모든 정점들의 최단거리
		// for(int i=0;i<n;i++)
		// 	cout << Dist[i] << ' ';
		// cout << "\n";
		bfs();
		for(int i=0;i<MaxPlace;i++)
			Dist[i] = INF;
		dijkstra();
	 if (Dist[d] == INF) cout << -1 << "\n";
	 else cout << Dist[d] << '\n';
	}
}
