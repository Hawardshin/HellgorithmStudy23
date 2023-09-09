#include <iostream>

using namespace std;

int twos[] ={1,2,4,8,16,32,64};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N; cin >> N;

	for(int i=0;i <= (1<<6);i++){
		int sum = 0;
		int ret = 0;
		for(int j=0;j < 7;j++){
			if (i & (1 << j)){
				sum+=twos[j];
				ret++;
			}
		}
		if (sum == N)
		{
			cout<< ret << "\n";
			return 0;
		}
	}
}