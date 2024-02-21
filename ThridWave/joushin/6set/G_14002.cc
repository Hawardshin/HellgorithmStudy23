#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//앞에 해당 숫자보다 작은 숫자가 있다면?
//해당숫자로 시작하는 최대값은 있을 수 없다.



int N;
int arr[1001];
int dist[1001];
int ar[1001];
int maxLen=1;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	for(int i=N-1;i>=0;i--){
		dist[i] = 1;
		// cout << i <<"\n";
		for(int j=i+1;j<N;j++){
			if (arr[i] < arr[j]){
				// cout << "xx:"<< j <<"\n";
				if (dist[i] < dist[j]+1){
					// cout << j << "가 업데이트"<<"\n";
					ar[i] = j;
					dist[i] =  dist[j] + 1;
					maxLen = max(maxLen,dist[i]);
				}
			}
		}
	}
	cout << maxLen<<"\n";
	if (maxLen == 1){
		cout << arr[0];
		return 0;
	}
	for(int i=0;i<N;i++){
		if (dist[i] == maxLen){
			int n = i;
			while (1){
				cout << arr[n] << " ";
				n = ar[n];
				if (ar[n] ==0){
					cout << arr[n] << " ";
					return (0);
				}
			}
		}
	}

}
