#include <iostream>
#include <tuple>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<tuple<int,int,int> > input;
int ret[20003];
bool vis[20003];
int vec_idx[20003];//링크가 저장된 곳의 저장된 위치를 이곳에 넣으면 바로 볼 수 있게 해줌.
int V, E, K;

// void print_tuple(){
// 	for(int i=0;i < E;i++){
// 		cout << "tuple:" << i <<  get<0>(input[i]);
// 		cout << get<1>(input[i]);
// 		cout << get<2>(input[i]) << "\n";
// 	}
// }
void daikstra(int start){
	// cout <<"start:"<< start << " "<<vec_idx[start]<< "\n";
	vis[start] = true;
	int min = 2000001;
	int min_idx = -1;
	vector<int>link_store;
	for(int i=vec_idx[start]; i < E;i++){//연결된 링크를 모두 탐색해서 작은 값으로 업데이트 이후, 가장 작은 value를 가진 곳으로 이동
		if (i == -1)
			return ;
		int a = get<0>(input[i]);
		if (a != start)
			break;
		int b = get<1>(input[i]);
		int c = get<2>(input[i]);
		if (ret[b] > ret[start] + c)
			ret[b] = ret[start] + c;
		if (!vis[b])
			link_store.push_back(b);
	}
	sort(link_store.begin(),link_store.end());
	for(auto it : link_store){
		// if (!vis[it])
			daikstra(it);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>V >> E >> K;
	fill(ret, ret+V + 1, 200001);
	fill(vec_idx, vec_idx+V+1, -1);
	for(int i=0;i < E;i++){
		int a,b,c;
		cin >> a>> b>>c;
		input.push_back({a,b,c});
	}
	// print_tuple();
	sort(input.begin(),input.end());//입력된 튜플값 정렬
	// print_tuple();
	int size_ = E;
	int bef = get<0>(input[0]);//시작값은 0번째 인덱스에 있는 값.
	vec_idx[bef] = 0;// 벡터 n의 위치를
	for(int i=0;i < size_;i++){
		if (bef != get<0>(input[i])){//이전 값과 다른 부분이 생겼다는 건 그 값이 처음 등장한다는 의미이다.
			vec_idx[get<0>(input[i])] = i;//처음 등장한 값이 몇번째 인덱스로 접근하면 바로 볼 수 있는지 저장.
			bef =get<0>(input[i]);//bef값을 업데이트 한다.
			// cout <<"idx:" <<i << "\n";
		}
	}
	// cout << "ret"<<ret[6] << "\n";
	ret[K] = 0;//시작점의 거리는 0입니다.
	daikstra(K);
	for(int i=1;i <= V;i++){
		if (ret[i] == 200001)
			cout << "INF\n";
		else
			cout <<  ret[i] <<"\n";
	}
}