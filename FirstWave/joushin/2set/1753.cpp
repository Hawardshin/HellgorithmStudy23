#include <iostream>
#include <queue>

using namespace std;

#define INF_ 200001
vector<pair<int,int> > input[20003];//togo, cost
int ret[20003];
bool vis[20003];
int V, E, K;

void daikstra(int start){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	ret[start] = 0;
	pq.push({0,start});//cost, link
	while(!pq.empty()){
		auto lowest_link =pq.top();
		int cur_cost = lowest_link.first;
		int togo = lowest_link.second;
		pq.pop();
		for(int i=0;i<input[togo].size();i++){
			int next_node = input[togo][i].first;//연결된 링크가 가는 노드의 번호
			int connect_cost = input[togo][i].second;//연결된 경로에서 다음 노드로 가는 데 드는 비용
			if (ret[next_node] > connect_cost + cur_cost){//다익스트라 알고리즘상 이미 방문했던 노드로 다시 들어오지 않기 때문에 굳이 vis를 만들지 않아도 됩니다.
				ret[next_node] = connect_cost + cur_cost;
				pq.push({connect_cost + cur_cost, next_node});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>V >> E >> K;
	fill(ret, ret+V + 1, INF_);
	for(int i=0;i < E;i++){
		int a,b,c;
		cin >> a>> b>>c;
		input[a].push_back({b,c});//togo, cost
	}
	daikstra(K);
	for(int i=1;i <= V;i++){
		if (ret[i] == INF_)
			cout << "INF\n";
		else
			cout <<  ret[i] <<"\n";
	}
}