#include <iostream>
#include <algorithm>
using namespace std;



int A[12];
int calc[4];
int N;
//덧셈,뺄셈,곱셈,나눗셈

int max_ret=-1000000001;
int min_ret= 1000000001;
void recur(int num,int idx){
	if (idx == N){
		max_ret = max(num,max_ret);
		min_ret = min(num,min_ret);
		return ;
	}else {
		if (calc[0] >0){
			calc[0]--;
			recur(num+A[idx],idx+1);
			calc[0]++;
		}
		if (calc[1]>0){
			calc[1]--;
			recur(num-A[idx],idx+1);
			calc[1]++;
		}
		if (calc[2]>0){
			calc[2]--;
			recur(num*A[idx],idx+1);
			calc[2]++;
		}
		if (calc[3]>0){
			calc[3]--;
			recur(num/A[idx],idx+1);
			calc[3]++;
		}
	}
}

int main(){
	 cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	cin >> calc[0] >> calc[1] >> calc[2] >> calc[3];
	recur(A[0],1);
	cout << max_ret << "\n"<< min_ret << "\n";
}