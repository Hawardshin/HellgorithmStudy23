#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,K;
pair<int,int> walk[101];//time, money
pair<int,int> bike[101];
int DP_TIME[101];
int DP_MONEY[101];
int MINUS_TIME[101];
int MINUS_MONEY[101];
void input(){
	// ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> N >> K;
	for(int i=0;i<N;i++){
		int a,b,c,d;
		cin >> a >>b>>c >>d;
		walk[i] = {a,b};
		bike[i] = {c,d};
		if (i !=0){
			if (a > c){
				DP_TIME[i] = DP_TIME[i-1]+ a;
				DP_MONEY[i] = DP_MONEY[i-1] + b;
				MINUS_TIME[i] = abs(a-c);
				MINUS_MONEY[i] = abs(b-d);
			}else{
				DP_TIME[i] = DP_TIME[i-1]+ c;
				DP_MONEY[i] = DP_MONEY[i-1]+d;
				MINUS_TIME[i] = abs(a-c);
				MINUS_MONEY[i] = abs(b-d);
			}
		}
		else{
			if (a > c){
				DP_TIME[i] =  a;
				DP_MONEY[i] = b;
				MINUS_TIME[i] = abs(a-c);
				MINUS_MONEY[i] = abs(b-d);
			}else{
				DP_TIME[i] =  c;
				DP_MONEY[i] = d;
				MINUS_TIME[i] = abs(a-c);
				MINUS_MONEY[i] = abs(b-d);
			}
		}
		cout << "|DP_TIME:" << DP_TIME[i] << " | DP_MONEY:" <<DP_MONEY[i] <<"|\n";
	}
}

int main(){
	input();
	
}
