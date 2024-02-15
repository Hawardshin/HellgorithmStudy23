#include <iostream>
#include <algorithm>
#include <queue>
#define COST second
#define WEG first

int N,K;
using namespace std;

pair<int, int> stone[300001];//{가격, 무게}
int pack[300001]; //최대무게
bool vis[300001];


int main(){
	cin >> N>> K;
	for(int i=0;i<N;i++){
		cin >> stone[i].WEG >> stone[i].COST;
	}
	priority_queue<int> Q;
	for(int i=0;i<K;i++){
		cin >> pack[i];
	}
	sort(stone,stone+N);
	sort(pack,pack+K);
	long long ret =0;
	int i =0;
	// cout << "--------------stone-------------\n";
	// for(int i=0;i<N;i++){
	// 	auto s = stone[i];
	// 	cout << "비용:"<< s.first << ", 무게 :" << s.second << "|";
	// }
	// cout << "\n";
	// cout << "--------------PACK-------------\n";
	// for(int i=0;i<K;i++){
	// 	cout <<  pack[i] << ",";
	// 	// cout << "비용:"<< s.first << ", 무게 :" << s.second << "|";
	// }
	// cout << "\n";
	for(int k=0;k<K;k++){
		while (i<N){
			int sCost = stone[i].COST;
			int sWeg = stone[i].WEG;
			if (pack[k] >= sWeg)
				Q.push(sCost);
			else 
				break;
			i++;
		}
		if (!Q.empty()){
			ret+=Q.top();
			Q.pop();
		}
	}
	cout << ret<<"\n";
}