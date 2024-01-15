#include <iostream>

using namespace std;

int n, c, r;
long long res=0;

void loop(int x, int y, int cnt){

    if (x==c && y==r){
        cout<<res;
        exit(0);
    }

    if (x+cnt >= c && y+cnt >= r && cnt>=2){
        loop(x, y, cnt/2);
        loop(x, y+cnt/2, cnt/2);
        loop(x+cnt/2, y, cnt/2);
        loop(x+cnt/2, y+cnt/2, cnt/2);
    }
    else {
        res += (cnt*cnt);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>c>>r;

    int N=1;
    for (int i=0; i<n; i++)
        N*=2;

    loop(0,0,N);

    return 0;
}
