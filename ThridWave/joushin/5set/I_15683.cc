#include <iostream>
#include <cmath>
#include <vector>
#define X first
#define Y second
using namespace std;

int N,M;
int table[9][9];
vector<pair<int,int>> camera;

int minSize = 1000000000;

void printTab(){
	cout << "-----------------\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << table[i][j];
		}
		cout << "\n";
	}
}

int calcSize(){
	int cnt = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if (table[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

void SeeN(int y,int x){
	for(int i=y;i>=0;i--){
		if (table[i][x] == 6)
			break;
		if (table[i][x] == 0)
			table[i][x] = 7;
		else if (table[i][x]>=7)
			table[i][x]++;
	}
}

void unSeeN(int y,int x){
	for(int i=y;i>=0;i--){
		if (table[i][x] == 6)
			break;
		if (table[i][x] == 7)
			table[i][x] = 0;
		if (table[i][x]>=7)
			table[i][x]--;
	}
}

void SeeW(int y,int x){
	for(int i=x;i>=0;i--){
		if (table[y][i] == 6)
			break;
		if (table[y][i] == 0)
			table[y][i] = 7;
		else if (table[y][i] >=7)
			table[y][i]++;
	}
}

void unSeeW(int y,int x){
	for(int i=x;i>=0;i--){
		if (table[y][i] == 6)
			break;
		if (table[y][i] == 7)
			table[y][i] = 0;
		if (table[y][i] >=7)
			table[y][i]--;
	}
}


void SeeS(int y,int x){
	for(int i=y;i<N;i++){
		if (table[i][x] == 6)
			break;
		if (table[i][x] == 0)
			table[i][x] = 7;
		else if (table[i][x]>=7)
			table[i][x]++;
	}
}

void unSeeS(int y,int x){
	for(int i=y;i<N;i++){
		if (table[i][x] == 6)
			break;
		if (table[i][x] == 7)
			table[i][x] =0;
		if (table[i][x]>=7)
			table[i][x]--;
	}
}
void SeeE(int y,int x){
	for(int i=x;i<M;i++){
		if (table[y][i] == 6)
			break;
		if (table[y][i] == 0)
			table[y][i] = 7;
		else if (table[y][i] >=7)
			table[y][i]++;
	}
}

void unSeeE(int y,int x){
	for(int i=x;i<M;i++){
		if (table[y][i] == 6)
			break;
		if (table[y][i] == 7)
			table[y][i] = 0;
		if (table[y][i] >=7)
			table[y][i]--;
	}
}



void recur(int idx){
	if (idx == camera.size()){
		minSize = min(minSize,calcSize());
		// printTab();
		return ;
	}else {
		auto c = camera[idx];
		int cr = table[c.Y][c.X];
		switch (cr){
			case 1 :
				SeeN(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				SeeE(c.Y,c.X);
				recur(idx+1);
				unSeeE(c.Y,c.X);
				SeeS(c.Y,c.X);
				recur(idx+1);
				unSeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);
				unSeeW(c.Y,c.X);
				break;
			case 2 :
				SeeN(c.Y,c.X);
				SeeS(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				SeeE(c.Y,c.X);
				recur(idx+1);
				unSeeW(c.Y,c.X);
				unSeeE(c.Y,c.X);
				break;
			case 3 :
				SeeN(c.Y,c.X);
				SeeE(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeE(c.Y,c.X);
				SeeE(c.Y,c.X);
				SeeS(c.Y,c.X);
				recur(idx+1);
				unSeeE(c.Y,c.X);
				unSeeS(c.Y,c.X);
				SeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);
				unSeeW(c.Y,c.X);
				unSeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				SeeN(c.Y,c.X);
				recur(idx+1);
				unSeeW(c.Y,c.X);
				unSeeN(c.Y,c.X);
				break;
			case 4 :
				SeeE(c.Y,c.X);
				SeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);

				unSeeE(c.Y,c.X);
				unSeeS(c.Y,c.X);
				unSeeW(c.Y,c.X);

				SeeN(c.Y,c.X);
				SeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeS(c.Y,c.X);
				unSeeW(c.Y,c.X);

				SeeN(c.Y,c.X);
				SeeE(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeE(c.Y,c.X);
				unSeeW(c.Y,c.X);

				SeeN(c.Y,c.X);
				SeeE(c.Y,c.X);
				SeeS(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeE(c.Y,c.X);
				unSeeS(c.Y,c.X);
				break;
			case 5 :
				SeeN(c.Y,c.X);
				SeeE(c.Y,c.X);
				SeeS(c.Y,c.X);
				SeeW(c.Y,c.X);
				recur(idx+1);
				unSeeN(c.Y,c.X);
				unSeeE(c.Y,c.X);
				unSeeS(c.Y,c.X);
				unSeeW(c.Y,c.X);
			break;
		}
	}
}

int main(){
	// cout << (long long) pow(4,8) * 64<< "\n";
	cin >> N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> table[i][j];
			if (1<=table[i][j] && table[i][j] <=5){
				camera.push_back({j,i});
			}
		}
	}
	recur(0);
	cout << minSize<<"\n";
}