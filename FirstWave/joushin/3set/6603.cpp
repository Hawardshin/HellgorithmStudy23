//8C6 8*7 /2
//그냥 백트래킹으로 풀면 될듯
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
bool vis[14];
int input[14];
int ret[14];
bool is_has[50];//0부터 49까지의 수
using namespace std;
void back_traking(int max_size,int now_size,int start){
	if (now_size == 6){
		for(int i=0;i < 6;i++){
			cout << ret[i] << " ";
		}
		cout << "\n";
	}
	else {
		for(int i=start; i < max_size;i++){
			if (vis[i] == false){
				vis[i] = true;
				ret[now_size] = input[i];
				back_traking(max_size, now_size + 1,i+1);
				vis[i] = false;
			}
		}
	}
}

void solve_one(int size){
	sort(input, input+size);
	// for(int i=0;i<size;i++) cout << "input::" <<input[i] << ' ';
	back_traking(size,0,0);
	memset(vis,0,sizeof(vis));
	memset(is_has,0,sizeof(is_has));
}

int main(){
	ios::sync_with_stdio(0);
	int input_size;
	while (1){
		cin >> input_size;
		if (input_size == 0)
			return (0);
		for(int i =0;i < input_size;i++){
			cin >> input[i];
		}	
		solve_one(input_size);
		cout << "\n";
	}
}