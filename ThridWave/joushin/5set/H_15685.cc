//다음 해당 숫자까지 거리를 저장?
//다음 해당 숫자 남은 갯수 저장
//거리가 맞는듯?


//3구
//1,2,3,4,3,2,1
//1뽑고 4 꽂고, 
//4 뽑고 1 꽂고

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, K;
int input[101];

bool vis[101];
int tap_size = 0;

// 현재 멀티탭에 있는 숫자 중 다음에 안 나오거나 가장 멀리 있는 녀석을 뽑는다.
// 멀티탭에 꽂혀있는 제품들
int findMinCost(int i){
	if (vis[input[i]] == true)
		return -1;
	int Num = 10000000;
	int Len = -1;
	for(int j=0;j<=100;j++){
		bool flag=false;
		if (vis[j] == false)
			continue;
		for(int k=i+1;k<K;k++){
			// cout << "k : "<< input[k] << "\n";
			if (j == input[k]){
				if (Len < k-i){
					Num = j;
					Len = k-i;
				}
				flag  =true;
				break;
			}
		}
		if (!flag)
			return j;
	}
	return Num;
}


int main(){
	cin >> N >> K;
	for(int i=0;i<K;i++){
		cin >> input[i];
	}
	// cout << "-----------input--------\n";
	// for(auto a: input){
	// 	cout << a << " ";
	// }
	// cout << "\n";
	int ret = 0;
	for(int i=0;i<K;i++){
		if (tap_size < N){
			if (vis[input[i]] == false){
				vis[input[i]] = true;
				tap_size++;
			}
		}else {
				// cout << input[i] << " 이거 "<< "\n";
				int idx = findMinCost(i);
				if (idx == -1)
					continue;
				// cout << idx << "터트림\n";
				vis[idx] = false;
				vis[input[i]] = true;
				ret++;
		}
	}
	cout << ret << "\n";
}