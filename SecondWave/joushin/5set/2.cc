#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,m;

int main(){
	cin >> n >>m;
	priority_queue<long long,vector<long long>,greater<long long>> PQ;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		PQ.push(a);
	}
	for(int i=0;i<m;i++){
		long long a = PQ.top();
		PQ.pop();
		long long b = PQ.top();
		PQ.pop();
		PQ.push(a+b);
		PQ.push(a+b);
	}
	long long sum = 0;
	while (!PQ.empty()){
		sum += PQ.top();
		PQ.pop();
	}
	cout << sum<<"\n";
}
