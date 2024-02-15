#include <iostream>
#include <algorithm>
#include <vector>
#define Y first
#define X second
using namespace std;
int N;
vector<pair<int,int>> input; // 사이즈와 시작점.

bool compare(pair<int,int> a ,pair<int,int> b){
	if (a.first > b.first)
		return true;
	if (a.first < b.first)
		return false;
	if (a.second > b.second)
		return true;
	return false;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >>b;
		input.push_back({b, a});
	}
	sort(input.begin(),input.end(),compare);
	int start = 1000000005;
	int ret = 0;
	for(int i=0;i<input.size();i++){
		int ix = input[i].X;
		int iy = input[i].Y;
		// cout << ix << "," << iy << "\n";
	
		if (ix <= start&&  iy <= start){
			// cout << "update\n";
			start = ix;
			ret++;
		}else if (ix > start){
			// cout << "only up\n";
			start = ix;
		}
		
	}
	
	cout << ret<<"\n";
}

/*
8
1 3
2 3
3 3
4 4
5 5
6 6
7 7
3 6

답 : 6


3
4 4
4 4
1 4

기댓값 3

4
1 1
1 2
2 2
2 3

4

11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

답 : 4

2
1 1000000000
1 1000000000

답 : 1

*/