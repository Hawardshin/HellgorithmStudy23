#include <iostream>
#include <string>
#define NAME "Messi "
#define SHOUT "Gimossi "
#define RESULT "Messi Messi Gimossi\n"

//6,8의 연속
/*
A는 6개
B는 8개

A
A B
A B A
A B A A B
A B A A B A B A 
A B A A B A B A A B A A B
A B A A B A B A A B A A B A B A A B A B A 
A B A A B A B A A B A A B A B A A B A B A A B A A B A B A A B A A B


1[A]
2[A B]
3[2 1]
4[3 2]
5[4 3]
6[5 4]
7[6 5]
*/

using namespace std;
int M;
string bef = "Messi ";
string ret="Messi Gimossi ";
void input(){
	cin >>M;
}

void	solve(){

	while (M > ret.size()){
		string tmp = bef;
		M-=bef.size();
		bef = ret;
		ret = tmp + ret;
	}
	// cout << ret << '\n';
	if (ret[M-1] == ' ')
		cout << "Messi Messi Gimossi\n";
	else 
		cout << ret[M-1] << "\n";
}

int main(){
	input();
	solve();
}