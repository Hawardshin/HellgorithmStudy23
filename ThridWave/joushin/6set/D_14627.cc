#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll pa[1000001];
ll paSum=0;
ll S,C;

bool canCut(ll l){
	ll cnt =0;
	for(ll i=0;i<S;i++){
		cnt += (pa[i] / l);
		if (cnt  >=C) 
			return true;
	}
	return false;
}

ll BS(ll st,ll ed){
	if (st> ed)
		return 0;
	ll mid = (st+ed) /2;
	// cout << mid<<"\n";
	if (canCut(mid)){
		if (!canCut(mid+1))
			return mid;
		else 
			return BS(mid+1,ed);
	}
	else 
			return BS(st,mid-1);
}

int main(){
	cin >> S>> C;
	for(ll i=0;i<S;i++){ 
		cin >> pa[i];
		paSum+=pa[i];
	}
	sort(pa,pa+S);
	ll L = BS(1,pa[S-1]);
	cout << paSum - (L*C) << "\n";
}