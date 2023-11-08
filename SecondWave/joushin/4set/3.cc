#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
int t_case;
int n;//편의점 갯수
int home_x, home_y;
int dest_x,dest_y;
bool vis[101];
//-32768 ~ 32767 이므로 65535가 32767로 0이 -32768로
//20개씩 50미터
//즉 1개당 50미터이므로
//최대 이동거리 1000미터
using namespace std;

//정답을 만들 수 있으면  true
//없다면  false
bool make_ret(vector<pair<int,int>> &store,int now_x,int now_y){
	int store_s = store.size();
	int f_dist_y = abs(now_y - dest_y);
	int f_dist_x = abs(now_x - dest_x);
	int f_dist = f_dist_y + f_dist_x; // 현재 위치에서 도착지점까지 거리
	if (f_dist <= 1000)
		return (true);
	for(int i=0;i<store_s;i++){
		if (vis[i])
			continue;
		int dist_x = abs(now_x - store[i].first);
		int dist_y = abs(now_y - store[i].second);
		int store_dist = dist_x + dist_y;
		if (store_dist > 1000)
			continue;
		// int s_dist_y = abs(store[i].first - dest_x);
		// int s_dist_x = abs(store[i].second - dest_y);
		// int s_dist = s_dist_x + s_dist_y; //새로 가는 가게 위치에서 도착 지점까지 거리
		// if (s_dist > f_dist)
		// 	continue;
		vis[i] =true;
		if (make_ret(store,store[i].first,store[i].second))
			return true;
		vis[i] = false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t_case;
	for(int i=0;i< t_case;i++){
		vector<pair<int,int>>store;
		cin >> n;
		cin >> home_x >> home_y;
		int x,y;
		for(int j=0;j<n;j++){
			cin >> x >> y;
			store.push_back({x,y});
		}
		cin >> dest_x >> dest_y;
		if (make_ret(store,home_x,home_y))
			cout << "happy\n";
		else
			cout << "sad\n";
		memset(vis,0,sizeof(vis));
	}
}