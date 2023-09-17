#include <iostream>
#include <vector>
using namespace std;
bool sosu[4000001];
vector<int> sosu_ar;
long long sum_ar[4000001];
int ret =0;
int s,e,sum;
void Eratos(int n){//구글 위키백과 참고
	if (n <= 1)
		return ;
	for(long long i=2;i <=n;i++){
		if (!sosu[i]){
			//i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2에서 i*i로 개선할 수 있다.
			sosu_ar.push_back(i);
			for(long long j=i*i; j <=n;j+=i){
				sosu[j] = true;
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	Eratos(N);
	int sosu_num = sosu_ar.size();
	// for(auto it : sosu_ar) cout << it << " ";
	// cout << "\n";

	//e가 증가하면 합이 증가된다는 의미
	//s가 증가되면 합이 감소된다는 의미이다.
	if (sosu_num == 0)
	{
		cout << 0 << '\n';
		return (0);
	}
	while (e <= sosu_num) {
		if (sum < N) {
			sum += sosu_ar[e];
			e++;
			continue;
		}
		if (sum == N) 
			ret++;
		sum -= sosu_ar[s];
		s++;
  }
	cout << ret<< "\n";
}