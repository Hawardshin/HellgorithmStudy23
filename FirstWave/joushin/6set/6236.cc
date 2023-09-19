#include <iostream>

using namespace std;
int N,M;//일, 인출 횟수

int input_sum[100001];
int main(){
	cin >> N >> M;
	int tmp;
	int max_input = -1;
	for(int i=1;i <=N;i++){
		cin >> tmp;
		max_input = max(max_input,tmp);
		input_sum[i] = input_sum[i-1] + tmp;
	}
	int start = 1;
	int end = 1000000000;
	int ret = 1000000000;
	while (start <= end){
		int mid = (start+ end)/2;//인출 금액
		int day =0;//새로 충전하는 횟수
		int bef = 0;//누적합 때문에 존재
		for(int i=1;i <=N;i++){
			int use_money =input_sum[i] - input_sum[bef];
			if (day > M)
				break;
			if (use_money > mid){
				i--;
				day++;
				bef = i;
			}else if (use_money == mid){
				day++;
				bef = i;
			}
			else if (i == N)
				day++;
		}
		if (day <= M){
			ret = min(mid,ret);
			end = mid -1;
		}else {
			start = mid+1;
		}
	}
	cout << ret<< "\n";
}