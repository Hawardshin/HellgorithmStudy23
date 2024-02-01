/*

- 추가해야하는 가로선의 최소갯수
- i번 세로선의 결과가 i가 나와야 한다.
	놓는 가로선을 
	
	1     2     3     4    5 ->N 
1
  (1,1) (1,2) (1,3) (1,4) (a,b)
2

3

4

5

6

|
H

풀이 생각 
모든 놓을 수 있는 자리에 다리를 놓는 방식 
최대 30개 * 10 300칸 300 C 3
300개 중 순서에 상관없이 3개를 뽑으면 되므로 300*299*298 /3*2 대충 100*100*100*5 => 5,000,000 (5백만)

사다리를 타는 연산 시간 : 사다리당 높이만큼 연산 -> 전부 계산하는데 300번 연산 진행
만약 브루스 포스로 하게 되면  15억정도 진행됨 (15초..)

바뀌는 줄 이전의 결과 즉 그곳을 지나지 않는 경로를 가진 녀석들의 결과는 변경되지 않는다.
dp배열처럼 사용할 수 있지 않을까?
가로선은 서로 접하면 안된다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;
int N,H;//점선 가로, 점선 세로
int M;//놓인 가로
bool table[11][31]; // table[H][N-1]

int main(){
	cin >> N >> M >> H;
	for(int i=0;i<M;i++)
	{
		int a,b;
		cin >> a>>b;
		table[a][b] = true;
	}
}
