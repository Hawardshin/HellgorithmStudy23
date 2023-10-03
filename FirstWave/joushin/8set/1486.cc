//내려가거나 같은 곳은 1초
//(높이 차이)^2 초
#include <iostream>
#include <cstdlib>
#include <cmath>

#define MaxInput 676
#define INF 10000000
typedef long long ll;
//26*26
using namespace std;
int n,m;
int t,d;
int input[MaxInput];
ll arr[101][101];
ll moveArr[MaxInput][MaxInput];
ll di[4]={0,1,0,-1};
ll dj[4]={1,0,-1,0};
int high_len(char a){
	if ('a' <=a && a <= 'z')
		return (a-'a' + 26);
	else 
		return (a-'A');
}


int main(){
	cin >> n >> m >> t>> d;
	char tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> tmp;
			arr[i][j] =  high_len(tmp);
		}
	}
	for(int i=0;i<MaxInput;i++)
    for(int j=0;j<MaxInput;j++)
        if(i!=j)
          moveArr[i][j]=INF;
	//4방향을 보면 된다.
	//input[x + 1], input[x-1]input[x+ m], input[x-m] 탐색한다.
	//단, 여기서 x+1 % m == 0 인 경우 이동 불가
	//x % m==0인 경우 x-1로 이동불가
	//x-m < 0 인 경우 x -m으로 이동 불가
	//x+m > n*m 인 경우 x+m 이동 불가
	//이제 현재 위치와 이동할 위치간의 높이 차를 보고 비용을 계산하면 된다!
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)    
	          for(ll x=0;x<=4;x++){
	              int k=i+di[x];
	              int l=j+dj[x];
	              if(k<0||l<0||k>=n||l>=m) continue;
	              ll a=i*m+j;
	              ll b=k*m+l;
	              if(abs(arr[i][j]-arr[k][l])>t) continue;
	              if(arr[i][j]>=arr[k][l]) 
									moveArr[a][b]=1;
	              else 
									moveArr[a][b]=(arr[i][j]-arr[k][l])*(arr[i][j]-arr[k][l]);
	          }

	//k : 거쳐가는 노드
	for(int k=0;k<n*m;k++){
		//i : 출발노드
		for(int i=0;i<n*m;i++){
			//j : 도착노드
			for(int j=0;j<n*m;j++){
				if (moveArr[i][k] + moveArr[k][j] < moveArr[i][j])
					moveArr[i][j] = moveArr[i][k] + moveArr[k][j];
			}
		}
	}
	// for(int i=0;i<n*m;i++){
	// 	for(int j=0;j<n*m;j++){
	// 		cout <<moveArr[i][j] << "|";
	// 	}
	// 	cout << "\n";
	// }
	int max_high = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (moveArr[0][i*m+j] == INF || moveArr[i*m+j][0] == INF)
			continue;
			if (moveArr[0][i*m+j] + moveArr[i*m+j][0] > d)	
				continue;
			if (max_high < arr[i][j])
				max_high =  arr[i][j];
		}
	}
	cout << max_high << "\n";
}
