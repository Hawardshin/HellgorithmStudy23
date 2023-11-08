#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string input;
//- 인 경우 연산자 뒤에 괄호가 음수를 만드는 경우에는 올 수가 있다.
// 
int ret = -2147483647;

int calc(int a, int b, char oper){

	switch (oper)
	{
	case ('+'):
		return (a + b);
	case('-'):
		return (a - b);
	case('*'):
		return (a * b);
	}
	return -1;
}

void recur(int idx, int now_num){
	if (idx > N -1){
		ret = max(ret, now_num);
		return;
	}
	//괄호로 묶는다 = 이전 + 괄호 계산
	if (idx + 2 < N){
		int next = calc(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
		if (idx ==0)
			recur(idx + 4, calc(now_num, next, '+'));
		else 
			recur(idx + 4, calc(now_num, next, input[idx - 1]));
	}
		if (idx ==0)
			recur(idx + 2, calc(now_num,  input[idx] -'0', '+'));
		else 
			recur(idx + 2, calc(now_num,  input[idx]-'0', input[idx - 1]));
}

int main(){
	cin >> N;
	cin >> input;
	recur(0,0);
	cout << ret << "\n";
}