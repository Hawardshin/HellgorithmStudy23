#include <iostream>

using namespace std;

int N;
int table[101][101];
unsigned long long ret[101][101];

void printTab(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << ret[i][j];
		}
		cout << "\n";
	}
	cout << "--------------------------\n\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> table[i][j];
		}
	}
	ret[0][0] = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if (table[i][j] == 0)
				continue;
			if (i + table[i][j] <N)//새로축
			{
				ret[i+table[i][j]][j] += ret[i][j];
			}
			if (j+ table[i][j] < N)// 가로축
			{
				ret[i][j+table[i][j]] += ret[i][j];
			}
		}
	}
	cout << ret[N-1][N-1]<<"\n";
}