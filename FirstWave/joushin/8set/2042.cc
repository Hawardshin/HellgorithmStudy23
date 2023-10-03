#include <iostream>
#include <string>
using namespace std;

int n,k,m;
long long Fenwick_Tree[2000002];
long long input[1000001];
void update(int idx, long long value){
	while (idx <= n){
		Fenwick_Tree[idx] = Fenwick_Tree[idx]+ value;
		idx = idx + (idx & -idx);
	}
}


void make_FenwickTree(){
	for(int i=1;i<=n;i++)
		update(i,input[i]);
}

long long sum (int idx){
	long long result =0;
	while (idx>0){
		result = result+ Fenwick_Tree[idx];
		idx = idx - (idx & -idx);
	}
	return result;
}

int main(){
	cin >> n>>k>>m;
	for(int i=1;i<=n;i++) cin >> input[i];
	make_FenwickTree();
	long long a,b,c;
	long long ret;
	for(int i=0;i<m+k;i++){
		cin >> a >> b>>c;
		if (a == 1){
			long long diff = c-input[b];
			input[b] = c;
			update(b,diff);
		}
		else{
			ret = sum(c)- sum(b-1);
			cout << ret << "\n";
		}
	}
}