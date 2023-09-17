#include <iostream>
#include <algorithm>
#include <vector>
#define MAP_MAX 51
using namespace std;
int min_ = 2147483646;
class Rotate{
	public : 
		Rotate(int r,int c,int s){
			starty = r-s;
			startx = c-s;
			endy = r+s;
			endx = c+s;
		}
		int startx;
		int starty;
		int endx;
		int endy;
};

int input[MAP_MAX][MAP_MAX];
int backup[MAP_MAX][MAP_MAX];
int N, M,K;

void	printArr(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << input[i][j];
		}
		cout << "\n";
	}
	cout << "-----------------------\n";
}

void rotateBoarder(int sx,int sy,int ex,int ey){
	int tmp = input[sy][sx];
	for(int i = sy;i<ey;i++) input[i][sx] = input[i+1][sx];
	for(int i = sx;i<ex;i++) input[ey][i] = input[ey][i+1];
	for(int i = ey;i>sy;i--)input[i][ex] = input[i-1][ex];
	for(int i = ex;i>sx;i--)input[sy][i] = input[sy][i-1];
	input[sy][sx+1] = tmp;
}

void rotateArr(Rotate &r){
	int sx= r.startx;
	int sy = r.starty;
	int ex = r.endx;
	int ey = r.endy;
	while (sx < ex){
		rotateBoarder(sx,sy,ex,ey);	
		sx++;
		sy++;
		ex--;
		ey--;
	}
	// printArr();
	
}

int main(){
	cin >> N>>M>>K;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> input[i][j];
			backup[i][j] = input[i][j];
		}
	}
	int r,c,s;
	vector<Rotate> ar;
	for(int i=0;i<K;i++){
		cin >> r>> c>>s;
		ar.push_back(Rotate(r,c,s));
	}
	vector<int> permu;
	for(int i=0;i < K;i++)
		permu.push_back(i);
	do{
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++)
				input[i][j] = backup[i][j];
		}
		for(auto it : permu){
			rotateArr(ar[it]);
		}
		for(int i1=1;i1<=N;i1++){
			long long sum = 0;
			for(int j1=1;j1<=M;j1++){
				sum+= input[i1][j1];
			}
			if (sum < min_)
				min_ = sum;
		}
	}while (next_permutation(permu.begin(),permu.end()));
	cout << min_<<"\n";
}