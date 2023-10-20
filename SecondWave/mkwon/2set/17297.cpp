#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 39; 
int f[max_n] = {0, 5, 13}, m;
string s = "Messi Gimossi";

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>m;

    m--; // 인덱스 0부터
    for(int i = 3; i <= max_n; i++){
		f[i] = f[i-1] + f[i-2] + 1;
	} 
	for(int i = max_n; i >= 2; i--){
		if(m >= f[i]) m -= (f[i] + 1);
	}

    if(m == 5 || m == -1) cout << "Messi Messi Gimossi" << "\n";
	else cout << s[m] << "\n";

    return 0;
}

// 1 5 (Messi)
// 2 13 (Messi Gimossi)
// 3 19 (13 + 1 + 5)
// 4 33 (19 + 1 + 13)
// 5 51 (33 + 1 + 19)