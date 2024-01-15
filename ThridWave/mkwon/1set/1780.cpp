#include <iostream>

using namespace std;

int n, mone=0 , zero=0, one=0;
int tab[2500][2500]={0,};

void loop(int x, int y, int cnt){

    int cmp = tab[x][y];
    int flag = 0;

    for(int i=x; i<x+cnt; i++){
        for(int j=y; j<y+cnt; j++){
            if (tab[i][j] != cmp){
                flag=1; break;
            }
        }
    }

    if (!flag){
        if (cmp == 1) one++;
        if (cmp == 0) zero++;
        if (cmp == -1) mone++;
        return;
    }

    loop(x, y, cnt/3);
    loop(x, y+cnt/3, cnt/3);
    loop(x, y+cnt/3*2, cnt/3);

    loop(x+cnt/3, y, cnt/3);
    loop(x+cnt/3, y+cnt/3, cnt/3);
    loop(x+cnt/3, y+cnt/3*2, cnt/3);

    loop(x+cnt/3*2, y, cnt/3);
    loop(x+cnt/3*2, y+cnt/3, cnt/3);
    loop(x+cnt/3*2, y+cnt/3*2, cnt/3);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab[i][j];
        }
    }

    loop(0,0,n);

    cout<<mone<<"\n"<<zero<<"\n"<<one;

    return 0;
}
