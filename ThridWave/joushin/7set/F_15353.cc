#include <iostream>
#include <stack>
using namespace std;

int main(){
	string a,b;
	cin >> a>>b;
	int aIdx = a.size()-1;
	int bIdx = b.size()-1;
	int up = 0;
	stack<int> s;
	while (aIdx >= 0 || bIdx >= 0){
		int a1 = 0;
		int b1 = 0;
		int sum =0;
		if (aIdx >=0){
			a1 = a[aIdx]-'0';
		}
		if (bIdx >=0){
			b1 = b[bIdx]-'0';
		}
		sum = a1+b1+up;
		// cout << sum <<"\n";
		// exit(0);
		if (sum>=10){
			up=1;
			sum-=10;
		}else 
			up = 0;
		s.push(sum);
		aIdx--;
		bIdx--;
	}
	if (up == 1)
		cout << 1;
	while (!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << "\n";
}