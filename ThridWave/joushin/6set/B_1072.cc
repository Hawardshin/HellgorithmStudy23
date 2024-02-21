#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

ll X,Y;


int BS(ll st, ll ed, ll toFind){
	if (st > ed)
		return -1;
	int mid = (st+ed)/2;
	// cout << mid<<"\n";
	ll Z = ((Y+mid)*100)/(X+mid);
	ll bef = ((Y+mid-1)*100)/(X+mid-1);
	if (Z > toFind && bef == toFind)
		return (mid);
	if (Z <= toFind)
		return BS(mid+1,ed,toFind);
	else
		return BS(st,mid-1,toFind);
	return -1;
}

int main(){
	cin >> X >>Y;
	ll Z = (Y*100)/X;
	if (Z >= 99){
		cout << -1<<"\n";
		return 0;
	}
	cout << BS(1,X,Z)<<"\n";
}