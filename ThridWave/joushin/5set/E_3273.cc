#include <iostream>

using namespace std;
int num[1000001];
int N;



int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		num[a]++;
	}
	int x;
	cin >>x;
	int sum=0;
	for(int i=1;i<=x/2;i++){
		if (num[i] && x-i && x-i <= 1000000  &&num[x-i]){
			if (i == x-i){
				sum+= num[i]/2;
			}else{
				sum+= (num[i]*num[x-i]);
			}
		}
	}
	cout << sum<<"\n";
}
