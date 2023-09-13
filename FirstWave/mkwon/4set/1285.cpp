#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2147483647

int n,res=INF,tab[25]={0,};
string s;

void loop(int x){
    if(x == n + 1){	
		int sum = 0;
		for(int i=1; i<= 1 << (n-1); i*=2){
			int cnt = 0;
			for(int j=1; j<=n; j++){
				if(tab[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		res = min(res, sum);
		return;
	}
	
	tab[x] = ~tab[x]; //뒤집기
	loop(x + 1);
	tab[x] = ~tab[x]; //복구
	loop(x + 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s;
        int v = 1;
		for(int j=0; j<s.size(); j++){
			if(s[j] == 'T') tab[i] |= v;
			v *= 2;
		}
    }

    loop(1);
    cout<<res;

    return 0;
}