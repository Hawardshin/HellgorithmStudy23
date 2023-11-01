#include <iostream>
#include <algorithm>
using namespace std;
int coin[13];
int a_ar1[4];
int a_ar2[4];
char a;
int b_ar1[4];
int b_ar2[4];
char b;
int c_ar1[4];
int c_ar2[4];
char c;
bool cant_ans[13];

void input(){
	for(int i=0;i<4;i++){
		cin >> a_ar1[i];
	}
	cin >> a;
	for(int i=0;i<4;i++){
		cin >> a_ar2[i];
	}
	if (a == '='){
		for(int i=0;i<4;i++){
			cant_ans[a_ar2[i]] = true;
		}
		for(int i=0;i<4;i++){
			cant_ans[a_ar1[i]] = true;
		}
	}else {
		for(int i=1;i<=12;i++){
			if (find(a_ar1,a_ar1+4, i) == (a_ar1 +4) && find(a_ar2,a_ar2+4, i) == (a_ar2 +4)){
				cant_ans[i] = true;
			}
		}
	}

	for(int i=0;i<4;i++){
		cin >> b_ar1[i];
	}
	cin >> b;
	for(int i=0;i<4;i++){
		cin >> b_ar2[i];
	}
	if (b == '='){
		for(int i=0;i<4;i++){
			cant_ans[b_ar2[i]] = true;
		}
		for(int i=0;i<4;i++){
			cant_ans[b_ar1[i]] = true;
		}
	}else {
		for(int i=1;i<=12;i++){
				if (find(b_ar1,b_ar1+4, i) == (b_ar1 +4) && find(b_ar2,b_ar2+4, i) == (b_ar2 +4)){
				cant_ans[i] = true;
			}
		}
	}

	for(int i=0;i<4;i++){
		cin >> c_ar1[i];
	}
	cin >> c;
	for(int i=0;i<4;i++){
		cin >> c_ar2[i];
	}
	if (c == '='){
		for(int i=0;i<4;i++){
			cant_ans[c_ar2[i]] = true;
		}
		for(int i=0;i<4;i++){
			cant_ans[c_ar1[i]] = true;
		}
	}else {
		for(int i=1;i<=12;i++){
			if (find(c_ar1,c_ar1+4, i) == (c_ar1 +4) && find(c_ar2,c_ar2+4, i) == (c_ar2 +4)){
				cant_ans[i] = true;
			}
		}
		
	}
}


int main(){
	input();

	// 1~12 중 더 크다고 생각
	// 1~12 중 더 작다고 생각
	for(int i=1;i<12;i++){
		if (cant_ans[i] != true)
			cout << i << "\n";
	}
}