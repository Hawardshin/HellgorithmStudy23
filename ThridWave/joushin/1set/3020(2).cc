#include <iostream>
#include <algorithm>

using namespace std;

int N,H;
int inputA[100001]; //아래 있는 기둥
int inputB[100001]; //위에 있는 기둥
int a_size=0;
int b_size=0;
int main(){
	cin >> N >> H;
	for(int i=0;i<N;i++) {
		if (i %2 ==0)
			cin >> inputA[a_size++];
		else 
			cin >> inputB[b_size++];
	}
	sort(inputA, inputA+a_size);
	sort(inputB, inputB+b_size);
	//A가 부서지는 상황 = 현재 높이 < A의 높이
	//B가 부서지는 상황 = 현재 높이 > H - B의 높이
	//구간 A는 A의 길이 순서대로 쭉 
	//구간 B는 B의 길이 순서대로 쭉
	//A의 가장 낮은 높이
	//B의 가장 높은 높이
}