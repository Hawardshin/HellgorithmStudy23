/*
이전의 이동기록을 다시 돌아가면서 해당 값을 넣어주면 됨
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;

bool vis[101][101];

pair<int,int> next_pos(pair<int,int> a,int dir){
	switch(dir){
		case 0: return (make_pair(a.X+1,a.Y));
		case 1: return (make_pair(a.X,a.Y-1));
		case 2 : return make_pair(a.X-1,a.Y);
		case 3 : return make_pair(a.X,a.Y+1);
	}
	cout <<"MAD\n";
	return make_pair(-1,-1);
}

int changeDir(int dir){
	dir++;
	if (dir ==4)
		dir = 0;
	return dir;
}


void makeCurve(vector<int> &s,int g,pair<int,int> pos){
	int dep = 0;
	while (dep<g){
		int ridx =  s.size()-1;
		for(int i=ridx;i>=0;i--){
			s.push_back(changeDir(s[i]));
			pos = next_pos(pos,changeDir(s[i]));
			if (pos.Y < 0 || pos.Y >100 || pos.X < 0 || pos.X >100)
				continue;
			vis[pos.Y][pos.X] = true;
		}
		dep++;
	}
}

int makeRet(){
	int cnt = 0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if (vis[i][j] && vis[i+1][j] && vis[i][j+1] && vis[i+1][j+1]){
				cnt++;
			}
		}
	}
	return cnt;
}


int main(){
	int N; cin >> N;
	for(int i=0;i<N;i++){
		int x, y ,d, g;
		cin >> x >> y >> d >> g;
		vector<int> store;
		store.push_back(d);
		vis[y][x] = true;
		pair<int,int> npos = next_pos({x,y},d);
		vis[npos.Y][npos.X] = true;
		makeCurve(store,g,npos);
	}
	cout <<  makeRet() << "\n";
}
