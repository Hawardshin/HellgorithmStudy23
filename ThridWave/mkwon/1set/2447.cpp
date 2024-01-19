#include <iostream>

using namespace std;

int n;
char tab[7000][7000]={0,};

void loop(int x, int y, int cnt){
    
    if (cnt == 3){
        tab[x+1][y+1]=' ';
        return ;
    }
    else {
        for (int i=x+cnt/3; i<x+cnt/3*2; i++){
            for (int j=y+cnt/3; j<y+cnt/3*2; j++){
                tab[i][j]=' ';
            }
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

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            tab[i][j]='*';
        }
    }

    loop(0,0,n);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<tab[i][j];
        }cout<<"\n";
    }

    return 0;
}
