#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T,n,m;
int inputA[1001];
int sumA[1001];
int inputB[1001];
int sumB[1001];

void input(){
	cin >>T >> n;
	for(int i=1;i<=n;i++){
		cin >> inputA[i];
	}
	cin >> m;
	for(int i=1;i<=m;i++){
		cin >> inputB[i];
		sumB[i] = sumB[i-1] + inputB[i];
	}
}

int second_permu(int A1, int A2){
	int aNum = sumA[A2] - sumA[A1];
	vector<bool> idx_arB(m-1,false);
	idx_arB.push_back(true);
	idx_arB.push_back(true);
	do{
		int B1=-2147483647,B2=-2147483647;
		for(int i=0;i<=m;i++){
			if (idx_arB[i])
			{
				if (B1 == -2147483647)
					B1 = i;
				else {
					B2 = i;
					int bNum = sumB[B2] - sumB[B1];
					if (bNum + aNum == T){
						return (1);
					}
					break;
				}
			}
		}
	}while (next_permutation(idx_arB.begin(),idx_arB.end()));
	return (0);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ret =0;
	input();
	vector<bool> idx_arA (n-1,false); //가장 앞 0을 포함하기 위해서 -2가 아니라 -1해줌
	for(int i=0; i<2; i++) idx_arA.push_back(true);
	
	do{
		int A1=-2147483647,A2=-2147483647;
		for(int i=0;i<=n;i++){
			if (idx_arA[i]){
				if (A1 == -2147483647)
					A1 = i;
				else if (A2 == -2147483647){
					A2 = i;
					ret += second_permu(A1,A2);
					break;
				}
			}
		}
	}while(next_permutation(idx_arA.begin(), idx_arA.end()));
	cout << ret << "\n";
}