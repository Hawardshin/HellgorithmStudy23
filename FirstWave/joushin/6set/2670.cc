#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAP_SIZE 10001
int N;
double DP[MAP_SIZE];
double maax = -1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> DP[i];
		maax = max(maax,DP[i]);
	}
	for(int i=1;i<N;i++){
		if (DP[i-1] >= 1)
			DP[i] *= DP[i -1];
		maax = max(maax, DP[i]);
	}
	cout << fixed;
	cout.precision(3);
	cout << maax << "\n";
}