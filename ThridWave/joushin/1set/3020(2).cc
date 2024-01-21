#include <iostream>
#include <algorithm>

using namespace std;

int N,H;
int inputA[100001]; //아래 있는 기둥
int inputB[100001]; //위에 있는 기둥
int a_size=0;
int b_size=0;
int broken[200001];
int minBroken = 200001;

int findAIdx(int to_find, int start, int end){
	int mid = (start+end) /2;
	if (inputA[mid] == to_find){
		for(int i=1;i<N;i++){
			if (mid == 0 ||  inputA[mid] != inputA[mid-i])
				return (mid -i+1);
		}
	}
	else if (start == end){
		return start;
	}
	else {
		if (inputA[mid] > to_find)
			return findAIdx(to_find,start,mid);
		else 
			return findAIdx(to_find, mid + 1, end);
	}
}

int findBIdx(int to_find, int start, int end){
	int mid = (start+end) /2;
	if (inputB[mid] == to_find){
		for(int i=1;i<N;i++){
			if (mid == 0 ||  inputB[mid] != inputB[mid-i])
				return (mid -i+1);
		}
	}
	else if (start >= end)
		return start;
	else {
		if (inputB[mid] > to_find)
			return findBIdx(to_find,start,mid);
		else
			return findBIdx(to_find, mid + 1, end);
	}
}


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
	for(int i=1;i<=H;i++){
		int a_broke = a_size - findAIdx(i,0,a_size);
		int b_broke = b_size - findBIdx(H-i+1,0,b_size);
		int brokenSum = a_broke + b_broke;
		broken[brokenSum]++;
		minBroken = min(minBroken,brokenSum);
	}
	cout <<  minBroken << " " << broken[minBroken] <<  "\n";
}