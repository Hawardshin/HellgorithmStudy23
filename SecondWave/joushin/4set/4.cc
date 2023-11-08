#include <iostream>
#include <algorithm>
using namespace std;
int N; //계란의 갯수
pair<int,int> eggs[8];
// 무게가 높은 녀석은 최대한 많은 계란을 쳐야만 한다.
// 무조건 한번 이상씩 들린다.
// 내구도는 그 이상으로 깨지는 상황 보다는 딱 맞는 무게로 깨지는 것이 좋다.
//상황 1 무게가 아주 높고 내구도도 아주 높은 경우 모든 계란은 그 녀석에 가서 박는게 좋다.
//상황 2 모두가 같은 무게인 경우 뭘 치더라도 상관없다.
//상황 3 모두 내구도와 무게가 같은데 하나의 내구도만 엄청나게 높은 경우
//가장 무게가 높은 녀석을 박는 경우의 수, 가장 내구도가 높은 녀석을 박는 경우
int DP[8][2];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		int guard, weight;
		cin >> guard >> weight;
		eggs[i]= {guard,weight};
	}

}