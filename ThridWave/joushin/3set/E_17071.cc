/*
수빈이 위치 : N
동생 위치 : K
수빈 이동 : +-1, *2
동생 이동 : 1, 1+2, 1+2+3, 1+2+3+4 ...

동생을 처음 만나는 시간 : time
0 <= 위치 <= 500000

동생 위치 500000 넘으면 -1, 못찾는 경우 -1
시간 제한 : 0.25초 -> 25,000,000
동생[지난시간] = 위치
- 방문에 대한 가지치기를 잘 모르겠다.
- 한번 방문했으면, 또 방문하는 일이 없는걸까?
1 2 가 있다고 치자.
1->2->4->8
2->3->5->8
답 : 3

5 17 
5->10->20
17->18->20
답 : 2

17 5
17->16->15->16->15
5-> 6 ->8 ->11->15
//이런 경우도 있기 때문에 버릴 수는 없다.

홀수와 짝수를 이용해보자.
한칸 이동할 때는 짝->홀, 홀->짝
2배할 때는 짝->짝, 홀->짝
동생 위치는 홀(+1)->홀(1+2)->짝(3+3)->짝(6+4)->홀(10+5)->홀(15+6)->짝(21+7)->짝(28+8)->홀(36+9)->홀(45+10)->짝(55+11)->짝(66+12)
현재 같은 위치를 반복하는게, 저런 경우 하는건데, 이건 일정 시간 이후에 즉 짝수배의 시간이후, 이곳을 방문한다면? 그 경우를 도착으로 처리해준다면 vis처리를 
일반 bfs처럼 하면 괜찮지 않을까? 


반례 : 21 70
21->42->41->40->80
70->71->73->76->80->85->91

반례 : 18 66
18->36->72
66->67->69->72->76->81->87

반례 : 7 37
7-> 6-> 12->13->26->52
37->38->40->43->47->52
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define TIME first
#define POS second
using namespace std;
int bro[500001];
bool vis[500001][2];
int N,K;
int mini = 500000000;
int main(){
	cin >> N >> K;
	int i =1;
	int pos = K;
	memset(bro,-1,sizeof(bro));
	while (pos <=500000){
		bro[pos] = i-1;
		// cout << "동생 위치" << pos<< "동생 도착 시간" <<bro[pos] << "\n";
		pos+= i;
		i++;
	}
	queue<pair<int,int>> Q;
	Q.push({0,N});
	vis[N][0] = true;
	while (!Q.empty()){
		auto q = Q.front();
		Q.pop();
		if (bro[q.POS] != -1 &&  bro[q.POS] >= q.TIME && (bro[q.POS]-q.TIME)%2 == 0)
			mini = min(bro[q.POS],mini);
		if (q.POS > 0 && !vis[q.POS-1][(q.TIME+1)%2]){
			Q.push({q.TIME+1,q.POS-1});
			vis[q.POS-1][(q.TIME+1)%2] = true;
		}
		if (q.POS < 500000 && !vis[q.POS+1][(q.TIME+1)%2]){
			Q.push({q.TIME+1, q.POS+1});
			vis[q.POS+1][(q.TIME+1)%2] = true;
		}
		if (q.POS*2 <=500000&& !vis[q.POS*2][(q.TIME+1)%2]){
			Q.push({q.TIME+1, q.POS*2});
			vis[q.POS*2][(q.TIME+1)%2] = true;
		}
	}
	if (mini== 500000000)
		cout << -1 << "\n";
	else 
		cout << mini << "\n";
}