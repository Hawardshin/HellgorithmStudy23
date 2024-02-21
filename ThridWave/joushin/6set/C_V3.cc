#include <iostream>
#include <vector>
#include <algorithm>
//정답

using namespace std;
//0,1,2,3 
//mid = 1 
int T,N,M;
int note[1000000];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>T;
	while (T){
		cin >> N;
		for(int i=0;i<N;i++) cin >> note[i];
		sort(note,note+N);
		cin >> M;
		for(int i=0;i<M;i++) {
			int tmp;
			cin >> tmp;
			auto a = (lower_bound(note,note+N,tmp));
			if (a >= note+N)
				cout << 0 <<"\n";
			else 
				cout << (*a == tmp) << "\n";
		}
		T--;
	}
}