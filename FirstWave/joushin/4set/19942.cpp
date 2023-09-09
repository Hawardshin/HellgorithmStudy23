#include <iostream>
#include <vector>
#include <string>
#define NUM_MAX 2147483647
using namespace std;
int N;//재료 갯수, 
int min_ar[4]; //(단,지,탄,비) 최소 영양분
int p,f,s,v,c; //각 줄별로 나오는 단, 지, 탄, 비, 가격
int arr[16][5];//인덱스 0번째부터 넣어주는데 단,지,탄,비,가격 으로 넣어줍니다. 결과엔 plus 1해주자.

int min_cost = NUM_MAX;
vector<int> ret;

void print_vec(vector<int> &ar){
	cout << "----------------\n";
	for(auto it : ar) cout << it << " ";
	cout << "\n";
	cout << "----------------\n";
}

void calc_min(vector<int> & idx_ar){
	int sum[5] = {0,};
	for(auto it : idx_ar){
		for(int i=0;i<5;i++){
			sum[i] += arr[it][i];
		}
	}
	for(int i=0;i < 4;i++){
		if (sum[i] < min_ar[i])
			return ;
	}
	if (min_cost >= sum[4]){
		if (min_cost == sum[4]){
			for(int i=0;i < idx_ar.size() && i < ret.size() ;i++){
				if (ret[i] == idx_ar[i]){
					if (i == ret.size() - 1)
						return;
					continue;
				}
				if (ret[i] < idx_ar[i])
					return ;
				else
					break;
			}
		}
		ret.clear();
		ret = idx_ar;//깊은 복사 되겠지?
		min_cost = sum[4];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<4;i++) cin >> min_ar[i];
	for(int i =0; i<N;i++){
		for(int j=0;j<5;j++) cin >> arr[i][j];
	}
	for(int i=0; i < (1 << N);i++){//모든 경우의 수를 본다.
		vector<int> idx_ar;
		for(int j=0; j < N; j++){//켜져 있는 모든 비트에 해당하는 인덱스를 담아주는 것
			if (i & (1 << j))//j번째 비트가 켜져있다면 
				idx_ar.push_back(j);
		}
		calc_min(idx_ar);
	}
	if (min_cost == NUM_MAX){
		cout << -1 << "\n\n";
		return (0);
	}
	cout << min_cost << "\n";
	for(auto it : ret){
		cout << it+1 << " ";
	}
	cout << "\n";
}
