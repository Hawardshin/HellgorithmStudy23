#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
int table[51][51];//지도
int valid[51][51];//치킨집 사용가능여부
int n,m;
vector<int> idx_ar;
vector<pair<int,int> >chk_ar;
int chk_size;

int min_point=21474836;

int	find_min(int y,int x)//y,x위치에서 거리인 치킨집을 찾는다.
{
	int len = 0;
	int min = 21474836;
	for (int i=1;i <= n; i++){
		for (int j=1;j <=n; j++){
			if (valid[i][j] == 1){
				len = abs(x - j) + abs(y - i);
				if(len < min)
					min = len;
			}
		}
	}
	return (min);
}

void	cal_point(){//최소 점수 저장
	int	min =0;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if (table[i][j] == 1)
				min += find_min(i,j);
		}
	}
	if (min < min_point)
		min_point = min;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;

	for (int i=1;i <=n;i++){
		for (int j=1;j <=n;j++){
			cin >> table[i][j];
			if (table[i][j] == 2){
				chk_ar.push_back({i,j});
				chk_size++;
			}
		}
	}
	for(int i=0;i < chk_size - m;i++) idx_ar.push_back(0);
	for(int i=0;i< m;i++)idx_ar.push_back(1);
	do{
		for(int i=0;i < chk_size;i++){
			if (idx_ar[i] == 1){
				int y = chk_ar[i].first;
				int x = chk_ar[i].second;
				valid[y][x] = true;
			}
		}
		cal_point();
		memset(valid, 0,sizeof(valid));
	}while (next_permutation(idx_ar.begin(), idx_ar.end()));
	cout<< min_point << "\n";
}