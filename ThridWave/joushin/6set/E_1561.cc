#include <iostream>
#define ll long long

using namespace std;

ll N,M;

ll play[10001];


ll rideNum(ll time){
	ll ret = M;
	for(int i=0;i<M;i++) ret+= time/play[i];
	return ret;
}

ll binSearch(ll st,ll ed){
	ll mid = (st+ed)/2;
	if (st == ed)
		return st;
	if (rideNum(mid) < N) return (binSearch(mid+1,ed));
	else {
		if (rideNum(mid-1) < N)
			return mid;
		return (binSearch(st,mid));
	}
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin >> play[i];
	}
	if (N <= M){
		cout << N <<"\n";
		return 0;
	}
	ll time = binSearch(0,60000000001);
	ll tmp = rideNum(time-1);
	 for (int i = 0; i < M; i++) {
		if (time % play[i] == 0) tmp++;
		if (tmp == N){
			cout << i +1 << "\n";
			return 0;
		}
	 }
}
