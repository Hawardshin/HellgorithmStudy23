#include <iostream>
/*
- 수식의 길이 N -> 19
- 괄호가 1개 
- 1부터 N까지의 결과
- A부터 B까지의 결과를 저장

*/
using namespace std;

int N;
string input;
int ret = 0;
int calc(int a,int b, char oper){
	switch (oper){
		case '+':
			return (a+b);
		case '*':
			return (a*b);
		case '-':
			return (a-b);	
	}
	return (-1);
}

void recur(int idx,int now_sum){ //현재 인덱스와 지금까지 합
	if (idx == N-1)
		ret = max(ret,now_sum);
	else 
	{
		int next = calc(input[idx]-'0', input[idx+2]-'0', input[idx+1]);//다음 계산값
		if (idx == 0)
			recur(idx+4, calc(now_sum, next,'+'));
		else
			recur(idx+4,calc(now_sum,next,input[idx-1]));
			
	}
}
// 1+2+3

int main(){
	cin >> N >> input;
	recur(0,0);
	cout << ret << "\n";
}