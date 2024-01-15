#include <iostream>

using namespace std;

int n, zero=0, one=0;
char tab[130][130]={0,};

void loop(int x, int y, int cnt){

    char cmp = tab[x][y];
    int flag = 0;

    for(int i=x; i<x+cnt; i++){
        for(int j=y; j<y+cnt; j++){
            if (tab[i][j] != cmp){
                flag=1; break;
            }
        }
    }

    if (!flag){
        if (cmp == '1') one++;
        if (cmp == '0') zero++;
        return;
    }

    loop(x, y, cnt/2);
    loop(x, y+cnt/2, cnt/2);
    loop(x+cnt/2, y, cnt/2);
    loop(x+cnt/2, y+cnt/2, cnt/2);
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

    cout<<zero<<"\n"<<one;

    return 0;
}
