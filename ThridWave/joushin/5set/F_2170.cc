#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N;
pair<int,int> input[1000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input[i].X >> input[i].Y;
	}
	sort(input,input+N);
	int start = input[0].X;
	int end = input[0].Y;
	long long ret = 0;
	for(int i=1;i<N;i++){
		if (end < input[i].X){
			ret+= (end-start);
			start = input[i].X;
			end = input[i].Y;
		}else if (input[i].Y > end) {
			end = input[i].Y;
		}
	}
	ret += (end-start);
	cout << ret <<"\n";
}