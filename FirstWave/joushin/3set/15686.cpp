#include <iostream>
#include <algorithm>
int table[51][51];//지도
int valid[51][51];//치킨집 사용가능여부
int n,m;

using namespace std;

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

void	valid_recur(int depth, int i,int j)//y,x
{
	if (depth == m)//치킨집 m개 선택하면 최소값 다 계산
		cal_point();
	if (i == n + 1)//y값이 높이 넘어가면 
		return ;
	for (int ti=i;ti <=n;ti++){
		for (int tj=1;tj<=n;tj++){
			if (i == ti && tj == 1)//x한칸 y한칸씩 움직여서
				tj = j;
			if (table[ti][tj] == 2){
				valid[ti][tj] = 1;
				if (tj == n)
					valid_recur(depth+1,ti+1,1);
				else
					valid_recur(depth+1,ti,tj + 1);
				valid[ti][tj] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;

	for (int i=1;i <=n;i++){
		for (int j=1;j <=n;j++){
			cin >> table[i][j];
		}
	}
	valid_recur(0,1,1);
	cout<< min_point << "\n";
}