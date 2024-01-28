/*
문서의 최대갯수
- . : 빈공간
- * : 벽
- $ : 훔쳐하는 문서
- 대문자 : 문
- 소문자 : 열쇠
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define  X first
#define  Y second
vector<pair<int,int>> start_p;
bool vis[101][101];
bool keyHave[26];
char table[101][101];
int n,h,w;
int ret=0;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void print_table(){
	cout << "-----------------------------\n";
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << table[i][j];
		}
		cout <<"\n";
	}
}
void input(){
	cin  >> h >>w;
	for(int j=0;j<h;j++){
		for(int k=0;k<w;k++){
			cin >> table[j][k];
		}
	}
	string keys;
	cin >> keys;
	for(char k : keys){
		if (k== '0')
			continue;
		keyHave[k - 'a'] = true;
	}
}

void findStart(){
	for(int i=0;i<h;i++){
		if (table[i][0] != '*')
			start_p.push_back({0,i});
		if (table[i][w-1] != '*')
			start_p.push_back({w-1,i});
	}
	for(int i=0;i<w;i++){
		if (table[0][i] != '*')
			start_p.push_back({i,0});
		if (table[h-1][i] != '*')
			start_p.push_back({i,h-1});
	}
}

bool bfs(int sy,int sx){
	bool update = false;
	queue<pair<int,int>>Q;
	Q.push({sx,sy});
	vis[sy][sx] = true;
	table[sy][sx] = '0';
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int nx = dx[i] + q.X;
			int ny = dy[i] + q.Y;
			if (nx <0 || ny < 0 || nx >=w || ny >=h)
				continue;
			char now = table[ny][nx];
			if (vis[ny][nx] == true)
				continue;
			if ('A'<=now && now<='Z' && !keyHave[now-'A'])
				continue;
			if (now == '*')
				continue;
			if ('a'<=now && now<='z' && !keyHave[now-'a']){
				update = true;
				keyHave[now-'a'] =true;
			}
			if (now == '$')
				ret++;
			vis[ny][nx] = true;
			table[ny][nx] = '0';
			Q.push({nx,ny});
		}
	}
	// print_table();
	return update;
}

bool searchAll(){
	bool update = false;
	for(auto p: start_p){
		char now = table[p.Y][p.X];
		if (vis[p.Y][p.X])
			continue;
		if ('A'<=now && now<='Z' && !keyHave[now-'A'])
			continue;
		if (now == '*')
			continue;
		if ('a'<=now && now<='z' && !keyHave[now-'a']){
			update = true;
			keyHave[now-'a'] =true;
		}
		if (now == '$')
			ret++;
		bool update_one = bfs(p.Y, p.X);
		if (update == false)
			update = update_one;
	}
	return !update;
}

void reset(){
	memset(vis,0,sizeof(vis));
	memset(keyHave,0,sizeof(keyHave));
	start_p.clear();
	ret = 0;
}

int main(){
	bool isEnd =false;
	cin >> n;
	for(int i=0;i<n;i++){
		input();
		findStart();
		while (!isEnd){
			isEnd =true;
			isEnd = searchAll();
			memset(vis,0,sizeof(vis));
		}
		cout << ret << "\n";
		reset();
		isEnd=false;
	}
}
