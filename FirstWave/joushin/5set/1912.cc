#include <iostream>
using namespace std;
#define INPUT_SIZE 100001
int s_idx, e_idx;
int N;
int input[INPUT_SIZE];
int max_ = -1;
int min_ =-1001;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> input[i];
		if (input[i] >min_)
			min_ = input[i];
	}
	long long sum = 0;
	while(e_idx < N){
		if (sum + input[e_idx] > 0){
			// cout << "sum : "<< sum << "input[e_idx]" << input[e_idx] << "\n";
			sum+= input[e_idx];
			if (max_ < sum)
				max_ = sum;
			// cout << e_idx << " " << sum << "|";
			e_idx++;
		}
		else{
			if (s_idx == e_idx){
				// cout << "A ";
				e_idx++;
				s_idx++;
				continue;
			}
			sum-= input[s_idx];
			s_idx++;
		}
	}
	if (max_ == -1){
		// cout << "sss\n";
		max_ = min_;
	}
	cout << max_<< "\n";
}