// 알파벳을 정렬을 해야함
// L,C를 입력을 받으면  C개의 숫자 중에서 L개를 선택.
// 단, 최소 한개의 모음과(a,e,i,o,u) 최소 2개의 모음이 있어야만한다!
// 이 조건은 C개의 숫자 중 모음이 몇개 있는지를 알면 나머지는 자음이므로 모음만 검사하는 걸 줄일 수 있다.
// 재귀의 종료는 L개가 된 경우에 종료되면서 출력
// 중간에 봐야 하는 조건 : 현재 모음의 갯수, 이미 내 벡터에 들어있는지 
#include <iostream>
#include <algorithm>
using namespace std;

int L,C;
bool vis[16];
char input[16];
char ret[16];
char s_alpha[5] = {'a','e','i','o','u'};


bool is_s_alpha(char &a){
	for(int i=0;i < 5;i++){
		if (a == s_alpha[i])
			return true;
	}
	return false;
}

//현재 모음의 갯수와 현재 인덱스와 현재 벡터에 들어있는 갯수
void back_tracking(int s_num, int start, int i_size){
	if (i_size == L){
		if (s_num < 1 || L - s_num < 2)
			return ;
		for(int i=0; i<L;i++) cout << ret[i];
		cout << "\n";
	}else {
		for(int i=start; i < C;i++){
			if (vis[i] == false){
				vis[i] = true;
				ret[i_size] = input[i];
				if (is_s_alpha(input[i]) == true)
					back_tracking(s_num+1, i+1, i_size + 1);
				else 
					back_tracking(s_num, i+1, i_size + 1);
				vis[i] = false;
			}
		}
	}
}

int main(){
	cin >> L >> C;
	for(int i=0;i < C;i++) cin >> input[i];
	sort(input, input+C);
	back_tracking(0,0,0);
}
