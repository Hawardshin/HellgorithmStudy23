#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d,p;
	vector<pair<int,int>> input;
	for(int i=0;i<n;i++){
		cin >> p >> d;
		input.push_back({d,p});
	}
	sort(input.begin(),input.end());
	priority_queue<int,vector<int>,greater<int>> PQ;
	for(auto it : input){
		PQ.push(it.second);
		if (PQ.size()> it.first)
			PQ.pop();
	}
	int sum = 0;
	while (!PQ.empty()){
		sum +=PQ.top();
		PQ.pop();
	}
	cout << sum << "\n";
}