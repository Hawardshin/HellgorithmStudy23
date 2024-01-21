#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[1000],b[1000];
vector<int> as,bs;
int T,n,m;
int main(){
	cin >> T >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n;i++){
		int sum = a[i];
		as.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum+=a[j];
			as.push_back(sum);
		}
	}
	cin >> m;
	for(int i=0;i<m;i++) cin >> b[i];
	for(int i=0;i<m;i++){
		int sum = b[i];
		bs.push_back(sum);
		for(int j=i+1;j<m;j++){
			sum+=b[j];
			bs.push_back(sum);
		}
	}

	sort(as.begin(),as.end());

	long long ans = 0;
	for(auto it : bs){
		int diff = T - it;
		int ub = upper_bound(as.begin(),as.end(),diff) - as.begin();//초과 숫자.
		int lb = lower_bound(as.begin(),as.end(),diff) - as.begin();//같거나 큰 숫자.
		ans += (ub - lb);
	}
	cout <<  ans <<"\n";
}