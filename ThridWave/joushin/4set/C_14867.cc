#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#define A first
#define B second
#define MAXSIZE 1000000
using namespace std;

int a,b,c,d;
int minMove = MAXSIZE;
map<pair<int,int>,int> vis;

void bfs(){
	queue<pair<int,int>> Q;

	Q.push({0,0});
	vis[{0,0}]=0;
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		// cout << q.A << ", " << q.B << "\n";
		if (q.A == c && q.B == d){
			cout << vis[{q.A,q.B}] << "\n";
			return ;
		}
		for(int way=0;way<6;way++){
			int na = q.A;
			int nb = q.B;
			switch(way){
				// 버리기 
				case 0 : na = 0;
					break;
				case 1 : nb = 0;
					break;
				//채우기
				case 2 : na = a;
					break;
				case 3 : nb = b;
					break;
				//옮기기
				case 4 :  //A쪽으로
					if (na+nb <= a){
						na = na+nb;
						nb = 0;
					}else{
						int tmp = na;
						na = a;
						nb = tmp+nb-a;
					}
					break;
				case 5 : //B쪽으로
					if (na+nb <=b){
						int tmp = na;
						na = 0;
						nb= tmp+nb;
					}else {
						na = na+nb-b;
						nb = b;
					}
					break;
			}
			if (vis.find({na,nb}) != vis.end()){
				// cout << na <<nb <<"실패\n";/
				continue;
			}
			// cout << na << nb << "성공\n";
			vis[{na,nb}] = vis[{q.A,q.B}]+1;
			Q.push({na,nb});
		}
	}
	cout << -1<<"\n";
}

int main(){
	cin >>a>>b>>c>>d;
	bfs();
}