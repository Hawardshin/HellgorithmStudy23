//답지봄
#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int arr[10001];
int DP[10001];
//1 {1}
//2 {1*2}{2}
//3 {1*3}{1,2}
//4 {1*4}{1*2,2}{2*2}
//5 {1*5}{1*3,2}{1,2*2}{5} 
//6 {1*6}{1*4,2}{1*2,2*2}{2*3}{1,5}

int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		cin >> arr[i];
	}
	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			if (DP[j - arr[i]]) 
				DP[j] += DP[j-arr[i]];
		}
	}
	cout << DP[K] <<"\n";
}