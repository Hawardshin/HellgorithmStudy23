#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
#define MaxWord 51
#define AlpahNum 31
//acnti -> 이건 그냥 있다고 생각하고 시작. 5이하면 0출력하고 끝
//b,d,e,f,g,h,j,k,l,m,o,p,q,r,s,u,v,w,x,y,z ->알파벳 총 21개
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0

bool dif_alpha[MaxWord][AlpahNum];//각 단어별로 해당 알파벳이 있는지 저장하는 배열
int dif_alpha_size[MaxWord];//각 단어별로 다른 알파벳이 몇개 있는지
int purmu[21]; //조합을 구할 떄 쓸 배열
int N,K;
int max_ = 0;
int alpha_idx(char a){
	if (a == 'b')
		return (0);
	if ('d'<=a  && a<='h')//1~5
		return (a - 'd' + 1);
	if ('j' <= a && a <='m')//6~9
		return (a - 'j' + 6);
	if ('o'<= a && a<='s')//10~14
		return (a - 'o' + 10);
	if ('u' <= a && a <= 'z')//15~20
		return (a - 'u' + 15);
	return (-1);
}

void solve(){
	int ret = 0;
	for(int i=0;i<N;i++){
		int size = 0;
		for(int j=0;j < 21;j++){
			if (purmu[j] && dif_alpha[i][j])
				size++;
		}
		if (size == dif_alpha_size[i])
			ret++;
	}
	if (max_ < ret)
		max_ = ret;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> N >> K;
	string tmp;
	for(int i=0;i<N;i++){
		cin >> tmp;
		int line_size = 0;
		for(auto it : tmp){
			int idx = alpha_idx(it);
			if (idx == -1)
				continue;
			if (dif_alpha[i][idx] == true)
				continue;
			dif_alpha[i][idx] = true;
			dif_alpha_size[i]++;
		}
	}
	if (K < 5){
		cout << 0 << "\n";
		return (0);
	}
	for(int i=0;i<K-5;i++)
		purmu[20 - i] = 1;
	do{
		solve();
	}while (next_permutation(purmu, purmu+21));
	cout << max_<< "\n";
}