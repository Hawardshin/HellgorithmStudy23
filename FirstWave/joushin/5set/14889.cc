#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> permu_ar;
int N;
int input[21][21];
bool now_permu[21];
int min_=2147483647;
void	solve(vector<int> &lar,vector<int> &rar){
	long long lsum =0;
	long long rsum=0;
	for(int i=0;i< N;i++){
		if (now_permu[i] == true){
			for(int j=0;j<lar.size();j++){
				if (lar[j] > i){
					lsum += input[i][lar[j]];
					lsum += input[lar[j]][i];
				}
			}
		}
		else{
			for(int j=0;j<rar.size();j++){
				if (rar[j] > i){
					rsum += input[i][rar[j]];
					rsum += input[rar[j]][i];
				}
			}
		}
	}
	int diff = abs(lsum - rsum);
	if (diff < min_)
		min_ = diff;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin >> input[i][j];
	}
	for(int i=1;i <=N;i++){
		if (i <= N/2)
			permu_ar.push_back(0);
		else 
			permu_ar.push_back(1);
	}


	do{
		vector<int> lar;
		vector<int> rar;
		for(int i=0;i<N;i++){
			if (permu_ar[i] == 1){
				now_permu[i] = true;
				lar.push_back(i);
			}
			else 
				rar.push_back(i);
		}
		solve(lar,rar);
		memset(now_permu,0,sizeof(now_permu));
	}while (next_permutation(permu_ar.begin(),permu_ar.end()));
	cout << min_ << "\n";
}