#include <iostream>
#include <algorithm>
#define AR_SIZE 200001
using namespace std;
int A,B;
int input[AR_SIZE];

bool is_exist(int n){
	int start = 0, end = A -1; 
	while (start <= end){
		int mid = (start + end)/2;
		if (input[mid] == n)
			return (true);
		else if (input[mid] > n)
			end = mid -1;
		else
			start = mid +1;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A>>B;
	int ret = A+B;
	for(int i=0;i<A;i++) cin>> input[i];
	sort(input,input+A);
	int tmp;
	for(int i=0;i<B;i++) {
		cin >> tmp;
		if (is_exist(tmp) == true)
			ret-=2;
	}
	cout << ret<<"\n";
}