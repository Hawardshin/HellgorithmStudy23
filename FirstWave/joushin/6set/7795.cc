#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T,N,M;//테케 갯수, A,B의 수

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> N >> M;
		priority_queue<int> Apq;
		priority_queue<int> Bpq;
		int tmp;
		int ret =0;
		for(int i=0;i<N;i++) {
			cin >> tmp;
			Apq.push(tmp);
		}
		for(int i=0;i<M;i++){
			cin >> tmp;
			Bpq.push(tmp);
		}
		while(!Apq.empty() && !Bpq.empty()){
			int atop = Apq.top();
			int btop = Bpq.top();
			if (atop> btop){
				Apq.pop();
				ret+=Bpq.size();
			}
			if (atop <= btop){
				Bpq.pop();
			}
		}
		cout << ret<< "\n";
	}
}
