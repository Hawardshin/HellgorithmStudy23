#include <iostream>
#define  MAX_INPUT_SIZE 100001
using namespace std;
long long input_sum[MAX_INPUT_SIZE];

int lecture_size, blue_ray_size;

int main(){
	int tmp;
	int input_max = -1;
	cin >> lecture_size >> blue_ray_size;
	for (int i=1;i<=lecture_size;i++){
		cin >> tmp;
		if (tmp > input_max)
			input_max = tmp;
		input_sum[i] = tmp + input_sum[i-1];
	}
	int start = 1;
	int end = input_sum[lecture_size];
	int ret_min = input_sum[lecture_size];
	while (start<= end){
		int mid = (start + end)/2;//강의 몇분?
		int bef_idx = 0;
		int split_lecture = 0;
		for(int i=1; i <= lecture_size;i++){
			if (split_lecture > blue_ray_size)
				break;
			if (i - bef_idx == 1 && input_max < input_sum[i] - input_sum[bef_idx]){
				split_lecture=blue_ray_size +1;
				break;
			}
			if (input_sum[i] - input_sum[bef_idx] == mid){
				split_lecture++;
				bef_idx = i;
			}
			else if (input_sum[i] - input_sum[bef_idx] > mid){
				split_lecture++;
				i--;
				bef_idx = i;
			}
			else if (lecture_size == i)
				split_lecture++;
		}
		if (split_lecture <= blue_ray_size){
			ret_min = min(ret_min,mid);
			end = mid -1;
		}else 
			start = mid + 1;
	}
	cout << ret_min <<"\n";
}