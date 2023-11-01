#include <iostream>

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int cnt5=0;
	while (true){
		if (n>=5){
			n-=5;
		}
		else 
			break;
		cnt5++;
	}
	int cnt2= 0;
	while (true){
		if (n == 0)
			break;
		if (cnt5 == 0 && n%2 != 0){
			cout << -1 << "\n";
			return (0);
		}
		else if (n >= 2){
			n-=2;
			cnt2++;
		}
		else {
			n +=5;
			n-=2;
			cnt5--;
			cnt2++;
		}
	}

	cout << cnt5+ cnt2<< "\n";
}