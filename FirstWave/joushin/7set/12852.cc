	#include <iostream>
	#include <vector>
	#define NUM_MAX 1000001
	using namespace std;

	pair<int,int> DP[NUM_MAX];//숫자는 오려면 어떤 연산을 수행해서 왔는지.
	//첫번째 크기 두번째 다음 숫자
	int N;
	int main(){
		ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
		cin >> N;
		DP[N] = {0,N};
		for(int i=N -1;i>0;i--){//
			int bef = i+1;
			int bef_size = DP[i+1].first;
			if (i *2 <= N && DP[i*2].first < bef_size){
				bef = i*2;
				bef_size = DP[i*2].first;
			}
			if ( i* 3 <= N && DP[i*3].first < bef_size){
				bef = i*3;
				bef_size = DP[i*3].first;
			}
			DP[i] = {bef_size + 1,bef};
		}
		vector<int> ret;
		for(int i=1; i <= N;i = DP[i].second){
			ret.push_back(i);
			if (i == N)
				break;
		}
		cout << ret.size()  -1<< "\n";
		for(int i = ret.size() - 1; i >= 0;i--) cout << ret[i] << " ";
		cout << "\n";
	}