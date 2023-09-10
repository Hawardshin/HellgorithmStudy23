//T는 뒷면, H는 앞면
//
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
char arr[21][21];
int reverse_num[21][21];
int N;
int min_T;
char t_ar[21][21];
void	change_ar(char &a){
	if (a == 'T')
		a = 'H';
	else 
		a = 'T';
}

int get_Tsize(int i){
	int  n = 0;
	for(int j=0;j < N;j++){
		if (t_ar[j][i] == 'T'){
			n++;
		}
	}
	return n;
}


void calc(int idx, vector<int> &ar){
	for(int i = 0; i < N;i++){
		for(int j=0;j<N;j++){
			t_ar[i][j] = arr[i][j];
		}
	}
	for(auto it : ar){
		for(int i=0;i < N;i++){//모든 열을 뒤집습니다.
			change_ar(t_ar[it][i]);
		}
	}
	int min = 0;
	for(int i=0;i < N;i++){//이제 행을 뒤집을 준비합니다.
		int T_size = get_Tsize(i);
		if (N - T_size < T_size)
			T_size = N - T_size;
		min += T_size;
	}
	if (min < min_T)
		min_T = min;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string tmp;
	cin >> N; cin.ignore();
	for(int i=0;i<N;i++){
		getline(cin,tmp);
		for(int j=0;j<N;j++) {
			arr[i][j] = tmp[j];
			if (tmp[j]== 'T')
				min_T++;
		}
	}
	vector<int> idx_ar;
	for(int i=0; i < (1 << N);i++){
		for(int j=0; j < N;j++) {
			if (i & (1 << j)){
				idx_ar.push_back(j);
			}
		}
		calc(0,idx_ar);
		idx_ar.clear();
	}
	cout << min_T << "\n";
}

