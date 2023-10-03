/*
+ : 1,2,3
* : 2,3,5
최대한 적은 수의 연산으로 N을 만드는 방법
N은 최대 1000이기 때문에 1000까지 숫자를 모두 각 숫자별 올 수 있는 최소값을 배열에 저장한다.

DP[1] =1,12
DP[2] =1,34
DP[3] =1,56
DP[4] = DP[2]+ DP[2](3434) 또는 DP[2] *2(1342)
DP[5] = DP[2] + DP[3] (3456) 또는 DP[1]*5 (5126)
DP[6] = DP[3]+ DP[3] (5656) 또는 DP[2]*3(3344)
DP[7] =
*/
#include <iostream>
#include <string>
using namespace std;

string DP[1001];
int t;
string mul_2(string& num){
	return("1"+ num+ "2");
}

string mul_3(string& num){
	return ("3"+ num+ "4");
}

string mul_5(string& num){
	return("5"+ num+ "6");
}

string makeDp(int now){
	string min_num = "9999999999999999999999999999999999999";
	string tmp = "";
	for(int i=1;now - i > 0;i++){
		string mul_num = "";
		if (i *5 == now)
			mul_num = mul_5(DP[i]);
		else if (i*3 == now)
			mul_num = mul_3(DP[i]);
		else if (i*2 == now)
			mul_num = mul_2(DP[i]);
		if (mul_num  != "" && mul_num.size()< min_num.size())
			min_num = mul_num;
		else if (mul_num.size() == min_num.size() && mul_num < min_num)
			min_num= mul_num;
		tmp = DP[i] + DP[now-i];
		if (min_num.size() > tmp.size())
			min_num = tmp;
		else if (min_num.size() == tmp.size() && min_num > tmp) 
				min_num = tmp;
	}
	return (min_num);
}
void print_ret(string&a){
	for (char word: a){
		switch(word){
			case('1'): 
				cout << '(';
				break;
			case ('2'):
				cout << ')';
				break;
			case('3') :
				cout << '{';
				break;
			case('4') : 
				cout << '}';
				break;
			case('5'): 
				cout << '[';
				break;
			case('6') : 
				cout << ']';
				break;
		}
	}
	cout << "\n";
}
	
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	DP[1] = "12";
	DP[2] = "34";
	DP[3] = "56";
	for(int i=4;i<=1000;i++){
		DP[i] =  makeDp(i);
		// cout << DP[i] << "\n";
	}
	cin >> t;
	int n;
	for(int i=0;i<t;i++){
		cin >> n;
		print_ret(DP[n]);
	}
}