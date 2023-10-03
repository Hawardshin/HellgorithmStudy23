#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<ll,ll>
#define maxVic 200
#define INF -987654321
using namespace std;


typedef struct { int u, v, w; }edge;
int n, m, graph[maxVic][maxVic], city[maxVic], pre[maxVic], s, f;
long long dist[maxVic];
bool visit[maxVic];
vector<edge> e;

bool dfs(int cur) {
	if (cur == f)return true;
	visit[cur] = true;
	bool chk = false;
	for (auto x : e) {
		if (x.u == cur && !visit[x.v])
			chk |= dfs(x.v);
	}
	return chk;
}

void Bellman_Ford(){
	dist[s] = city[s];
	pre[s] = -1;
	for (int k = 0; k < n-1; k++)
		for (auto x : e) {
			if (dist[x.u] != INF && (dist[x.v] < dist[x.u] - x.w + city[x.v]))
				dist[x.v] = dist[x.u] - x.w + city[x.v];
	}
}

void input(){
	for(ll i=0;i<maxVic;i++)
		dist[i] = INF;
	cin >> n >> s >> f >> m;
	edge a;
	for(ll i=0;i<m;i++){
		int st,ed,value;
		cin >> st>>ed>>value;
		 a.u = st;
		 a.v = ed;
		 a.w = value;
		e.push_back(a);
	}
	for(ll i=0;i<n;i++){
		cin >> city[i];
	}


	// for(ll i=0;i<m;i++)
	// 	cout << links[i].first.first << "," << links[i].first.second << "->" << links[i].second << "\n";
}

int main(){
	input();
	Bellman_Ford();
	if(dist[f] == INF) 
		cout <<  "gg\n";
	else {
		for (auto x : e) {
			if (dist[x.u] != INF && (dist[x.v] < dist[x.u] - x.w + city[x.v]))
				if (dfs(x.u)) {
					printf("Gee");
					return 0;
				}
		}
		 cout << dist[f] << "\n";
	}
	
}