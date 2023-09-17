//1. N개의 겹치는 숫자가 없다면 연속되는 수를 1개~N개까지 구하면 된다.
//2. 만약 앞에 있는 N개의 숫자 중 겹치는 숫자가 등장했다면 그 숫자와 그 숫자 전까지 있는 부분을 제외하고 다시 반복합니다.
//이걸 반복하면 구할 수 있을듯
//그렇다면 vis배열을 만들고 방문했는지 아닌지 여부 확인
//수열을 순서대로 담을 queue 만들기
//방문 되어 있다면 queue를 빼면서 vis를 다시 false로 바꾸고 방문 된 녀석까지 빼준다.
//끝까지 도달하거나, 같은 녀석이 나올때 계산을 올리면 된다.
#include <iostream>
#include <queue>
using namespace std;
bool vis[100001];
int input[100001];
int N;
queue<int> Q;
int ret;
//	n + n-1 + n-2 + n-3
//수학적으로 (n +1)*n  /2 
void	calcRet(int n){
	if (n <1)
		return ;
	ret += ((n+1) * n)/2;
}

//1. N개의 겹치는 숫자가 없다면 연속되는 수를 1개~N개까지 구하면 된다.
//2. 만약 앞에 있는 N개의 숫자 중 겹치는 숫자가 등장했다면 그 숫자와 그 숫자 전까지 있는 부분을 제외하고 다시 반복합니다.
//이걸 반복하면 구할 수 있을듯
//그렇다면 vis배열을 만들고 방문했는지 아닌지 여부 확인
//수열을 순서대로 담을 queue 만들기
//방문 되어 있다면 queue를 빼면서 vis를 다시 false로 바꾸고 방문 된 녀석까지 빼준다.
//끝까지 도달하거나, 같은 녀석이 나올때 계산을 올리면 된다.
#include <iostream>
#include <queue>
using namespace std;
bool vis[100001];
int input[100001];
int N;
queue<int> Q;
long long ret;
//	n + n-1 + n-2 + n-3
//수학적으로 (n +1)*n  /2 
void	calcRet(long long n){
	if (n <1)
		return ;
	ret += ((n+1) * n)/2;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input[i];
		if (vis[input[i]]== false){
			Q.push(input[i]);
			vis[input[i]] = true;
		}
		else {
			while (!Q.empty()){
				int front = Q.front();
				ret+= Q.size();//1, 12, 123, 1234, 12345
				if (front != input[i]){
					Q.pop();
					vis[front] = false;
				}
				else {//여기서 계산 해당 갯수로 만들수 있는 경우의수
					Q.pop();
					Q.push(input[i]);
					break;
				}
			}
		}
	}
	calcRet(Q.size());
	cout << ret<< "\n";
}
//다른 모범답안 궁금해서 가져와봄
/*
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) cin >> input[i];
	int end = 0;
	for(int start = 0; start <N; start++){
		while (end<N){
			if (vis[input[end]] == true)//방문한적이 있다면
				break;
			vis[input[end]] = true;
			end++;
		}
		ret+= (end-start);
		vis[input[start]]= false;
	}
	cout << ret<< "\n";
}
*/
