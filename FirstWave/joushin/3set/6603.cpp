//8C6 8*7 /2
//그냥 백트래킹으로 풀면 될듯
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
bool vis[14];
int input[14];
int ret[14];
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
	back_traking(size,0,0);
	cout << "\n";
	memset(vis,0,sizeof(vis));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string tmp;
	while (1){
		getline(cin,tmp);
		if (tmp == "0")
			return (0);
		int idx = 0;
		for(auto a: tmp){
			if (a == ' ')
				continue;
			input[idx] = a - '0';
			idx++;
		}
		solve_one(idx);
	}
}