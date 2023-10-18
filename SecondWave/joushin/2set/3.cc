#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2147483646
int N,M; //도시의 갯수, 버스의 갯수
int start_p,end_p;
vector<pair<int,int>> city[1001]; //앞이 비용, 뒤가 도시
// bool vis[1001];
int dist[1001];
void input(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a>>b>>c;
		city[a].push_back({c,b});
	}
	cin >> start_p >> end_p;
	for(int i=0;i<= N;i++){
		dist[i] = INF;
	}
	dist[start_p] = 0;
	// vis[start_p] = true;
}

void daikstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
	for(auto ci: city[start_p])
		PQ.push(ci);
	while (!PQ.empty()){
		auto links = PQ.top();
		PQ.pop();
		int link_cost = links.first;
		int link_city = links.second;
		if (dist[link_city] > link_cost){
			dist[link_city] = link_cost;
			for(auto ci: city[links.second]){
				ci.first += dist[link_city];
				PQ.push(ci);
			}
		}
	}
}


int main(){
	input();
	daikstra();
	cout << dist[end_p] << "\n";
}
