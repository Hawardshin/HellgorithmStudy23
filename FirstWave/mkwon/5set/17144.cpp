#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k,tab[55][55]={0,};

void spread(){
    int temp[55][55]={0,};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (tab[i][j] > 0){

                int cnt=0, munji=tab[i][j]/5;
                if (i!=0 && tab[i-1][j]!=-1){
                    temp[i-1][j]+=munji; cnt++;
                }
                if (j!=0 && tab[i][j-1]!=-1){
                    temp[i][j-1]+=munji; cnt++;
                }
                if (i!=n-1 && tab[i+1][j]!=-1){
                    temp[i+1][j]+=munji; cnt++;
                }
                if (j!=m-1 && tab[i][j+1]!=-1){
                    temp[i][j+1]+=munji; cnt++;
                }
                tab[i][j]-=munji*cnt;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tab[i][j]+=temp[i][j];
        }
    }
}

void windup(int x){
    for(int i=x-1; i>=0; i--) tab[i+1][0]=tab[i][0];
    for(int i=1; i<m; i++) tab[0][i-1]=tab[0][i];
    for(int i=1; i<=x; i++) tab[i-1][m-1]=tab[i][m-1];
    for(int i=m-1; i>=1; i--) tab[x][i+1]=tab[x][i];
    tab[x][0]=-1;
    tab[x][1]=0;
}

void winddown(int x){
    for(int i=x+1; i<=n-1; i++) tab[i-1][0]=tab[i][0];
    for(int i=1; i<m; i++) tab[n-1][i-1]=tab[n-1][i];
    for(int i=n-1; i>=x; i--) tab[i+1][m-1]=tab[i][m-1];
    for(int i=m-1; i>=0; i--) tab[x][i+1]=tab[x][i];
    tab[x][0]=-1;
    tab[x][1]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m>>k;
    int flag=0,x1,x2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
            if (tab[i][j] == -1 && !flag) { x1=i; flag=1; }
            else if (tab[i][j] == -1 && flag) { x2=i; }
        }
    }

    while (k--){
        spread();
        windup(x1);
        winddown(x2);
    }
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (tab[i][j] != -1) res+=tab[i][j];
        }
    }
    cout<<res;

    return 0;
}
