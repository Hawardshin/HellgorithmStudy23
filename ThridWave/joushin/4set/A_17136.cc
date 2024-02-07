#include <iostream>
#include <algorithm>
#include <queue>
#define X first 
#define Y second
using namespace std;

bool table[11][11];
int min_size = 100;
int haveToFill;
int colorPaper[6];

bool canFill(int x, int y, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++)
			if (!table[y+i][x+j])
				return false;
	}
	return true;
}

void PrintVis(){
	cout << "-----------------------\n";
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout << table[i][j];
		cout<< "\n";
	}
}

void fillVis(int x,int y,int len, bool is_attach){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			table[y+i][x+j] = is_attach;
		}
	}
}


void dfs(int x,int y, int cnt){
	// cout << "fuck"<<  x << y << "\n";
	while (table[y][x] == 0){
		if (++x>= 10){
			if (++y>=10){
				min_size = min(min_size,cnt);
				return ;
			}
			x = 0;
		}
	}
	if (min_size <= cnt)
		return ;
	for(int k=5;k>0;k--){
		if (x + k > 10 || y + k > 10 || colorPaper[k] == 5) continue;
		if (canFill(x,y,k)){
			fillVis(x,y,k,false);
			colorPaper[k]++;
			dfs(x,y,cnt+1);
			fillVis(x,y,k,true);
			colorPaper[k]--;
		}
	}
}

int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++) {
			cin >> table[i][j];
			if (table[i][j] == 1)
				haveToFill++;
		}
	}
	dfs(0,0,0);
	
	if (min_size == 100)
		min_size = -1;
	if (haveToFill == 0)
		min_size = 0;
	cout << min_size << "\n";
}