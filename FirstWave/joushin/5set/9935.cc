#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
abaabcdbcdcd
abcd
정답 : FRULA

mirkovC4nizCC44
C4
AABCBABCBABCCABCC
ABC
정답 : ABBCC
C4
C4
aabcbc
abc
정답 
*/
int findStringIdx(char a, string &s){
	for (int i=0;i<s.size();i++){
		if (s[i] == a)
			return (i);
	}
	return -1;
}


pair<char,int> S[1000001];//문자와 폭탄에서 몇번째 문자인지

void	print_All(int size){
	for(int i=0;i<size;i++) cout << S[i].first;
	cout << "\n";
}
int main(){
	string input, Bumb;
	cin >> input >>Bumb;
	int BumbIdx = -1;
	int BumbSize = Bumb.size();
	int StackIdx =0;
	for (int i =0;i < input.size();i++ ){
		int f_idx =findStringIdx(input[i],Bumb);//현재 문자가 폭탄에 몇번째 문자인지
		if (f_idx == BumbIdx+1)//나와야 할 인덱스가 나온경우
			BumbIdx++;
		else if (f_idx == 0 && f_idx < BumbIdx + 1)//현재 문자가 찾은 폭탄의 숫자보다 작은 거니까
			BumbIdx = f_idx;
		else
			BumbIdx = -1;
		S[StackIdx] = {input[i],BumbIdx};//이 문자는 몇번째 인덱스인지와 문자가 들어있다. 
		StackIdx++;
		if (BumbIdx == BumbSize - 1){
			StackIdx -=BumbSize;
			if (StackIdx != 0)
				BumbIdx = S[StackIdx -1].second;
			else 
				BumbIdx = -1;
		}
	}
	if (StackIdx== 0){
		cout << "FRULA\n";
		return (0);
	}
	for(int i = 0; i< StackIdx; i++) cout << S[i].first;
	cout << "\n";
}