/*
1. 주어진 계산대를 가득 채운다.
2. 계산대가 가득 찼다면 deque의 가장 앞의 값을 모두 꺼낸다.
3. 그 중 최솟값을 찾아서 그 최솟값 만큼 앞의 값에서 다 빼준다.
4. 나머지 값들 중 0이 아닌 값이 있다면 다시 deque의 앞에 push 해준다.
5. 다시 계산대를 가득 채운다.
*/
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#define ll long long
using namespace std;
deque<pair<ll,ll>>casher[100001];//계산대에 들어간 고객들// 물건 수와 id
priority_queue<int,vector<int> , greater<int>> left_cash;//빈 계산대 여기부터 순서대로 넣어야한다.
pair<int,int> input[100001];//물건의 수와 id
int n,k;
long long order_num = 1;//나가는 순서
ll ret = 0;
int main(){
	cin >> n>>k;
	for(int i=0;i<n;i++){
		int id,buy_product;
		cin >> id >> buy_product;
		input[i]={buy_product,id};
	}
	for(int i=1;i<=k;i++)
		left_cash.push(i);
	
	for(int i=0;i<n;i++){
		if (!left_cash.empty()){
			int c_next =left_cash.top();
			left_cash.pop();
			casher[c_next].push_back(input[i]);
		}else{
			i--;
			int min_product=2147483647;
			for(int j=1;j<=k;j++){
				pair<int,int> a = casher[j].front();
				if (min_product> a.first)
					min_product=a.first;
			}
			for(int j=k;j>0;j--){
				auto a = casher[j].front();
				casher[j].pop_front();
				if (a.first == min_product){
					ret += order_num*a.second;
					order_num++;
					left_cash.push(j);
				}else{
					casher[j].push_front({a.first - min_product, a.second});
				}
			}
		}
	}
	while (left_cash.size() != k){
		int min_product=2147483647;
			for(int j=1;j<=k;j++){
				if (casher[j].empty())
					continue;
				pair<int,int> a = casher[j].front();
				if (min_product> a.first)
					min_product=a.first;
			}
			for(int j=k;j>0;j--){
				if (casher[j].empty())
					continue;
				auto a = casher[j].front();
				casher[j].pop_front();
				if (a.first == min_product){
					ret += order_num*a.second;
					order_num++;
					left_cash.push(j);
				}else{
					casher[j].push_front({a.first - min_product, a.second});
				}
		}
	}
	cout << ret<< "\n";
}
