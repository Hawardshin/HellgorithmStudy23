#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MapSize 5

using namespace std;
/*
0  1  2  3  4 
5  6  7  8  9  
10 11 12 13 14 
15 16 17 18 19 
20 21 22 23 24 
*/

int mapStore[25] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24};
int idx_ar[25] = {1,1,1,1,1,1,1,0};//7개의 순열을 찾기 위한 배열
char table[MapSize][MapSize];
bool LinkChek[MapSize][MapSize];
bool vis[MapSize][MapSize];
int ret;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
//Y가 4가 넘어가는 순간 잘못 된 조건
//y가 몇개 들어가있는지, 현재 몇개 담았는지

bool isAllLink(int y,int x){
	queue<pair<int,int> >Q;
	Q.push({y,x});
	int size = 0;
	while (!Q.empty()){
	 auto a =	Q.front();
	 int mx = a.second;
	 int my = a.first;
	 Q.pop();
	 for(int i=0;i < 4;i++){
		int tx = mx + dx[i];
		int ty = my + dy[i];
		if (ty < 0 || tx < 0 || tx>=5 || ty>=5)
				continue;
		if (vis[ty][tx])
				continue;
		if (LinkChek[ty][tx])
		{
			vis[ty][tx] = true;
			size++;
			Q.push({ty,tx});
		}
	 }
	}
 if (size != 7)
	 	return false;
	return true;
}

bool isValid(vector<int> & vec){
	int doyunmpa = 0;
	int x,y;
	for(auto i : vec){
		y = i/5;
		x = i %5;
		if (table[y][x] == 'Y')
			doyunmpa++;
		if (doyunmpa > 3)
			return (false);
		LinkChek[y][x] = true;
	}
	if (!isAllLink(y,x))
		return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> table[i][j];
		}
	}
	sort(idx_ar,idx_ar+25);//순열 찾기 위해 오름차순으로 정렬
	vector<int> permu_store;
	do {
		for(int i=0;i < 25;i++){
			if (idx_ar[i] == 1){
				permu_store.push_back(mapStore[i]);//1부터 25까지 숫자중 7개가 모여서 push 됩니다.
			}
		}
		if (isValid(permu_store))// L이 3개가 넘지 않는지 확인
			ret++;
		memset(LinkChek,0,sizeof(LinkChek));
		memset(vis,0,sizeof(vis));
		permu_store.clear();
	} while (next_permutation(idx_ar,idx_ar + 25));
	cout << ret<< "\n";
}