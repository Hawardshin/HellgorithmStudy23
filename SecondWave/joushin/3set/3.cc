#include <iostream>
#include <algorithm>
#include <vector>
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
vector<int> can_ans;

void each_one(int *ar1, int *ar2, char &operator_){
	for(int i=0;i<4;i++) cin >> ar1[i];
	cin >> operator_;
	for(int i=0;i<4;i++) cin >> ar2[i];

	if (operator_ == '='){
		for(int i=0;i<4;i++) cant_ans[ar2[i]] = true;
		for(int i=0;i<4;i++) cant_ans[ar1[i]] = true;
	} else {
		for(int i=1;i<=12;i++){
			if (find(ar1,ar1+4, i) == (ar1 +4) && find(ar2,ar2+4, i) == (ar2 +4)){
				cant_ans[i] = true;
			}
		}
	}
}

void input(){
	each_one(a_ar1,a_ar2,a);
	each_one(b_ar1,b_ar2,b);
	each_one(c_ar1,c_ar2,c);
}


bool is_ok(int i, int*ar1,int *ar2, char oper){
	int cnt_1 = 0;
	int cnt_2 = 0;
		for(int j=0;j<4;j++){
			if (ar1[j] == i)
				cnt_1++;
			if (ar2[j] == i)
				cnt_2++;
			cnt_1++;
			cnt_2++;
		}
		switch(oper){
			case ('>') :
				if (cnt_1 > cnt_2)
					return true;
				break;
			case ('<') :
				if (cnt_1 < cnt_2)
					return true;
				break;
			case ('=') :
				if (cnt_1 == cnt_2)
					return true;
				break;
		}
		return false;
}

void	solve(){
	int ok_cnt = 0;
	int plus_minos =-1;
	int ret = 0;
	for(int i=1;i<=12;i++){
		if (true == cant_ans[i])
			continue;
		//i+의 경우
		if (!is_ok(i,a_ar1,a_ar2,a))
			continue;
		if (!is_ok(i,b_ar1,b_ar2,b))
			continue;
		if (!is_ok(i,c_ar1,c_ar2,c))
			continue;
		ok_cnt++;
		plus_minos=1;
		ret = i;
	}
	for(int i=1;i<=12;i++){
		if (true == cant_ans[i])
			continue;
		//i-의 경우
		if (!is_ok(i,a_ar2,a_ar1,a))
			continue;
		if (!is_ok(i,b_ar2,b_ar1,b))
			continue;
		if (!is_ok(i,c_ar2,c_ar1,c))
			continue;
		ok_cnt++;
		plus_minos=2;
		ret = i;
	}
	if (ok_cnt==1){
		cout << ret;
		if (plus_minos == 1)
			cout << "+\n";
		else
			cout << "-\n";
	}
	else if (ok_cnt==0){
		cout << "impossible\n";
	}else{
		cout << "indefinite\n";
	}

}

int main(){
	input();
	solve();
}
