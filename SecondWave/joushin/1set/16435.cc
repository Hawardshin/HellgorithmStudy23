#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int N,L;
int h;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		if (arr[i] <= L)
			L++;
		else 
			break;
	}
	cout << L << "\n";
}