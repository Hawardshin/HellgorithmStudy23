#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
bool vis[1000001];
queue<int> Q[2];

bool changeOneDigit(int p){
	bool update = false;
	while (!Q[p%2].empty()){
		int n = Q[p%2].front();
		Q[p%2].pop();
		for(int i=0;i<20;i++){
			int digit =	1 << i;
			int next_num = n^digit;
			if (next_num >N && next_num > n)
				continue;
			if (vis[next_num])
				continue;
			vis[next_num]=true;
			update = true;
			Q[(p+1)%2].push(next_num);
		}
	}
	return update;
}

int main(){
	cin >> N>> M;
	for(int i=0;i<M;i++){
		int input;
		cin >> input;
		Q[0].push(input);
		vis[input] = true;
	}
	int point=0;
	while (true){
		if (!changeOneDigit(point)){
			cout << point << "\n";
			return (0);
		}
		point++;
	}

}