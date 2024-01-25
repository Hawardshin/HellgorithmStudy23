#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int vis[100001];
int N,K;

void printRet(){
	int pos = K;
	cout << vis[pos] << "\n";
	stack<int> S;
	S.push(pos);
	while (pos != N){
		int toGo = vis[pos] -1;
		if (pos > 0 && toGo == vis[pos -1])
			pos = pos -1;
		else if (pos < 100000 && toGo == vis[pos+1])
			pos = pos + 1;
		else if (pos %2 == 0 && pos != 0 && toGo == vis[pos/2])
			pos = pos/2;
		S.push(pos);
	}
	while (!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
}

int main(){
	cin >> N >> K;
	fill(vis,vis+100001,100002);
	queue<int> Q;
	vis[N] = 0;
	Q.push(N);
	while (!Q.empty()){
		int pos = Q.front();
		Q.pop();
		if (pos == K){
			printRet();
			return 0;
		}
		if (pos < 100000 && vis[pos+1] > vis[pos] + 1){
			vis[pos+1] = vis[pos]+1;
			Q.push(pos+1);
		}
		if (pos>0 && vis[pos-1] > vis[pos]+1){
			vis[pos-1] = vis[pos] + 1;
			Q.push(pos-1);
		}
		if (pos*2 <= 100000 && vis[pos*2] > vis[pos] + 1){
			vis[pos*2] = vis[pos] + 1;
			Q.push(pos*2);
		}
	}
}