//pair로 받아서 시작점 기준으로 정렬.
//그 배열들을 쭉 채우고 남은 길이 챙겨뒀다가.
//다음 시작점 길이를 보고 남은 길이를 활용할 수 있으면 그 부분까지 활용
//안되면 그냥 다시 반복
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> input;
int N,L;
int ret;

int findDonePos(int start, int end){
	start--;//시작 지점도 덮어야하기 때문에.
	while (start < end-1){
		start += L;
		ret++;
	}
	return start;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> N >> L;
	int s,e;
	for(int i=0;i<N;i++){
		cin >> s >> e;
		input.push_back({s,e});
	}
	sort(input.begin(),input.end());
	int bef_done = -1;
	for (auto it : input){
		int start = it.first;
		if (start <= bef_done){
			start = bef_done +1;
		}
		bef_done = findDonePos(start, it.second);//여기서 결과도 계산
	}
	cout << ret<< "\n";
}