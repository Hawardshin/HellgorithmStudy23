#include <iostream>
#include <algorithm>
#include <queue>
#define ARR_SIZE 300001
using namespace std;
int N,M;
int input[ARR_SIZE];
int main(){
	cin >> N >> M;
	int end =-1 , start= 1;
	for (int i=0; i<M;i++) {
		cin >> input[i];
		if (input[i] > end)
			end = input[i];
	}
	int ret = end;
	sort(input,input+M);
	while (start<= end){
		int mid = (start+end) /2;
		int need_people = 0;
		for(int i=0;i<M;i++){
			int quotient  = input[i] / mid;
			int remainder  = input[i] % mid;
			if (remainder  != 0)
				need_people++;
			need_people+= quotient ;
		}
		if (need_people <= N){
			ret = min(ret,mid);
			end = mid - 1;
		}else 
			start = mid + 1;
		
	}
	cout << ret << "\n";
}