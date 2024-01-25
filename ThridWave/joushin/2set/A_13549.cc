#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
int N,K;
int moveS[100001];
bool vis[100001];


int main(){
	cin >> N >> K;
	fill(moveS,moveS+100001,100001);
	deque<int> DQ; //현재 위치
	DQ.push_back(N);
	vis[N] = true;
	moveS[N] = 0;
	while (!DQ.empty()){
		int aq = DQ.front();
		if (aq == K){
			cout << moveS[aq] << "\n";
			return 0;
		}
		DQ.pop_front();
		// for(int i = aq;i<=100000;i*=2){
		int i=aq*2;
		if (i<= 100000 && !vis[i])
		{
				if (i == K){
					cout << moveS[aq] << "\n";
					return 0;
				}
			vis[i] = true;
			moveS[i] = moveS[aq];
			DQ.push_front(i);
		}

		if (aq != 0 && !vis[aq-1]){
			DQ.push_back(aq-1);
			vis[aq-1] = true;
			moveS[aq-1] = moveS[aq] +1;
		}

		if (aq != 100000 && !vis[aq+1]){
			DQ.push_back(aq+1);
			vis[aq+1]=true;
			moveS[aq+1] = moveS[aq] +1;
		}
	}
}
