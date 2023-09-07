//일단 LVR트리 순회 방법인데 처음으로 떠오르는 건 stack
//주어진 방문 순서가 있다면 가장 먼저 도착한 녀석은 가장 아래 레벨 .
//만약 이게 2K-1개의 노드라는 조건이 없었다면 모두 탐색하는게 맞을 수 있지만 이건 모든 모드가 가특찬 트리여서
//수학적으로 해결해도 문제없어보인다.

// 2
//1 3

//   4
// 2   6
//1 3 5 7

//     8
//   4        12
// 2   6   10   14
//1 3 5 7 9 11 13 15
//최상위 노드는 2의 (높이-1)승
// (2의 높이 -2)승 부터  8씩 증가 2의 3승씩
//(2의 높이 -3)승 부터 + 2의 2승씩
//(2의 높이 -4)승 부터 2의 1승식

#include <iostream>
#include <cmath>
using namespace std;

int depth;
int input[1024];//최대 2^k -1개
int K;
int max_size;
void printALine(int depth){
	int i_unit = pow(2,K-depth);
	int move_size = pow(2, K - depth + 1);
	for(int i=i_unit;  i<= max_size + 1; i+=move_size){
		cout << input[i] << ' ';
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	max_size = pow(2, K) - 1;
	for(int i=1;i<= max_size;i++){
		cin >> input[i];
	}
	for(int i =1; i <= K;i++){
		printALine(i);
	}
}