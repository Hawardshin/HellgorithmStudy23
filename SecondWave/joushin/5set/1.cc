#include <iostream>

using namespace std;

long long N; //지역리그 갯수
long long M; //지역 리그 별 팀 수
long long k; //A=k*B;
long long D; //경기 숫자 제한
long long S; //전체 팀수 M*N
long long T;//테스트 케이스 갯수
//예로 지역리그 갯수 2, 팀수 3 경기 제한 60 k =3

// 지역리그 N개 리그: M*N*B/2*(M-1)*k
// 외부리그 경기 : M*N*B/2*(N-1)*M
// 총합 = M*N*((N-1)*M + (M-1)*k)*B/2
// N*(B/2)*
// 2 2 3 B / 2 + 2 1 3 B /2
// 6B + 3B
//9B < 60
//

int main(){
	//N,M,k,D
	//N*B/2 * (M-1)*K + N*B/2* (N-1)M
	//N*B/2((M-1)K + (N-1)(M))
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> T;
	for(long long i=0;i<T;i++){
		cin >> N >> M >> k>> D;
		long long a = M*N*((N-1)*M + (M-1)*k);
		int B = 0;
		while(a*B <=2*D)B++;
		if (B<=1)
			cout << -1<<"\n";
		else 
			cout << a*(B-1)/2<<"\n";
	}
}
