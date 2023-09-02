#include <iostream>

using namespace std;
int links[1001];
int main(){
	int N,M;
	cin >> N >> M;
	int a,b;
	int ret = 0;
	for(int i=0;i<M;i++){
		cin >> a >>b;
		if (links[a] ==0 && links[b] == 0)
			ret++;
		links[a]++; links[b]++;
	}
	cout << ret<<"\n";
}