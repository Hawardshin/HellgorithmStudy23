//1. 연결된 사람들을 links배열에 담음
//2. 모든 녀석들이 연결 되어있는지 확인
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define ARESIZE 11
using namespace std;
int N;
vector<int> links[ARESIZE];
int peoples[ARESIZE];
int people_sum;
int min_ = 2147483647;
bool vis[ARESIZE];
bool selected[ARESIZE];

bool isAllLink(vector<int>&ar){
	memset(vis,0,sizeof(vis));
	if (ar.size()==0 || ar.size() == N)
		return false;
	queue <int> Q;
	Q.push(ar[0]);
	int cnt = 1;
	vis[ar[0]] = true;
	while (!Q.empty()){
		int a = Q.front();
		Q.pop();
		for(auto next: links[a]){
			if (vis[next] || !selected[next])
				continue;
			cnt++;
			vis[next] = true;
			Q.push(next);
		}
	}
	if (cnt == ar.size())
		return true;
	return  false;
}

bool isLeftLink(){
	vector<int> ar;
	for(int i=1;i<=N;i++){
		if (selected[i] == false){
			ar.push_back(i);
			selected[i] = true;
		}
		else 
			selected[i] = false;
	}
	return (isAllLink(ar));
}

void solve(vector<int> &ar){//한 구역으로 정해진 인덱스가 들어있는 배열
	if (!isAllLink(ar))
		return ;
	int l_people = 0;
	for(auto it : ar) l_people += peoples[it];
	int r_people = people_sum - l_people;
	if (min_ > abs(l_people - r_people)){
		if (!isLeftLink())
			return ;
		min_ = abs(l_people - r_people);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++) {
		cin >> peoples[i];
		people_sum += peoples[i];
	}
	int n,l_tmp;
	for(int i=1; i<=N;i++){
		cin >> n;
		for(int j=1;j<=n;j++){
			cin >> l_tmp;
			links[i].push_back(l_tmp);
			links[l_tmp].push_back(i);
		}
	}
	for(int i=0;i < (1 << N); i++){
		vector<int> ar;
		for(int j=0;j < N;j++){
			if (i & (1 << j)){
				ar.push_back(j+1);
				selected[j+1] = true;
			}
		}
		solve(ar);
		memset(selected,0,sizeof(selected));
	}
	if (min_ == 2147483647)
		min_ = -1;
	cout << min_ << "\n";
}

