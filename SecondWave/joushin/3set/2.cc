#include <iostream>
#include <vector>
using namespace std;
long long ret = 0;
int T;
int how_many_num[10001];

int n_max = 0;


void	next_n_max(){
	for(int i = n_max; i >=0;i--){
		if (how_many_num[i] != 0){
			n_max = i;
			return ;
		}
	}
	n_max = -1;
}

void	solve(){
	int N;
	cin >> N;
	vector<int> input(N,0);
	for(int i=0;i<N;i++){
		int x;
		cin >> x;
		input[i] = x;
		if (x > n_max)
			n_max = x;
		how_many_num[x]++; 
	}
	int coin_cnt = 0;
	long long use_money = 0;
	for(int i=0;i<N;i++){
		how_many_num[input[i]]--;
		if (input[i] == n_max){
			ret = ret + ((coin_cnt * input[i]) - use_money);
			coin_cnt = 0;
			use_money = 0;
			next_n_max();
			if (n_max == -1)
				return ;
		}
		else {
			use_money+= input[i];
			coin_cnt++;
		}
	}

}

void init(){
	for(int i=0;i<10001;i++)
		how_many_num[i] = 0;
	n_max = 0;
	ret = 0;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
	cin >> T;
	int cnt = 0;
	
	while (cnt < T){
		solve();
		cout << ret << "\n";
		init();
		cnt++;
	}
}

