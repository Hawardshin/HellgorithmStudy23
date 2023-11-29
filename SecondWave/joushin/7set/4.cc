#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
string my_queue[100000];
int n1,n2;
int max_case = 1;
string max_ret= "";
int vis[10001];
int calc_D(int a){
	// cout << "bef::" << a << "\n";
	a=a*2;
	// cout << "calc_D" << a%10000<<"\n";
	return (a%10000);
}

int calc_S(int a){
	// cout << "bef::" << a << "\n";
	int ret =0;
	if (a == 0)
		ret = 9999;
	
	else ret = (a-1);
	// cout << "calc_S" << ret<<"\n";
	return (ret);
}


int calc_L(int a){
	// cout << "bef::" << a << "\n";
	int s = a/1000;
	a = a - s*1000;
	a=a*10;
	// cout << "calc_L" << a+s << "\n";
	return (a+s);
}

int calc_R(int a){
	// cout << "bef::" << a << "\n";
	int s = a%10;
	a = a/10;
	a += s*1000;
	// cout << "calc_R" << a<<"\n";
	return (a);
}



string calc(int n){
	max_case = 10000;
	max_ret = "";
	memset(vis,0,sizeof(vis));
	vis[n] = true;
	queue<int> Q;
	Q.push(n);
	int i =0;
	while (!Q.empty()){
		int a = Q.front();
		Q.pop();
		int a1= calc_D(n);
		int a2 = calc_S(n);
		int a3 = calc_L(n);
		int a4 = calc_D(n);
		Q.push(a1);
		Q.push(a2);
		Q.push(a3);
		Q.push(a4);
		i++;
	}
	return (max_ret);
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> n1 >> n2;
		cout << "ret:::"<< calc(n1);
	}
}
