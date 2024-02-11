#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,C;
int input[31];
//정렬, 누적합?
//어디서 부터 어디까지 가능한지 범위를 찾기
//0번째 숫자부터 a번째 숫자까지 가능하다면, 
void make_combi(vector<int> &v, int idx,int x,int end){
	if (x > C) return ;
	if (idx == end + 1){
		v.push_back(x);
		return ;
	}
	make_combi(v,idx+1,x+input[idx],end);
	make_combi(v,idx+1,x,end);
}

void print_vec(vector<int> &v){
	cout << "---------------\n";
	for(int a : v){
		cout << a << ",";
	}
	cout << "\n";
}

int main(){
	cin >> N >> C;
	for (int i=1;i<=N;i++){
		cin >> input[i];
	}
	//1. 반으로 나눠서 모든 조합을 구하고 두개로 나누니 조합의 합을 각각 vector로 저장하기
	int mid = N/2;
	vector<int> v1;
	vector<int> v2;
	make_combi(v1,1,0,mid);
	make_combi(v2,mid+1,0,N);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	// print_vec(v1);
	// print_vec(v2);
	//2. 저장한 조합의 합 배열을 이용해서 각각 이분탐색으로 정답 구하기.
	int ret = 0;
	for(auto a : v1){
		ret += upper_bound(v2.begin(),v2.end(),C-a) - v2.begin();
	}
	cout << ret<<"\n";
}
