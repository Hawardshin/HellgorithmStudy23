#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool vis[5][5];
int table[5][5];
//0부터 최대 16까지
// []
int n,m;//세로,가로
int max_sum;
void bruPos(int x,int y){
	if (y == n){
		int sum = 0;
		for(int i=0;i<n;i++){
			int tmp=0;
			for(int j=0;j<m;j++){
				if (vis[i][j])
					tmp = tmp*10+table[i][j];
				else {
					sum+=tmp;
					tmp=0;
				} 
			}
			sum+= tmp;
		}
		for(int i=0;i<m;i++){
			int tmp = 0;
			for(int j=0;j<n;j++){
				if (!vis[j][i]) tmp = tmp*10 + table[j][i];
				else {
					sum += tmp;
					tmp=0;
				}
			}
			sum+= tmp;
		}
		max_sum = max(max_sum,sum);
	}else {
		if (x == m){
			bruPos(0,y+1);
		}else {
			vis[y][x] = true;
			bruPos(x+1,y);
			vis[y][x] = false;
			bruPos(x+1,y);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char a ;
			cin >> a;
			table[i][j] = a - '0';
		}
	}
	bruPos(0,0);
	cout << max_sum << '\n';
}