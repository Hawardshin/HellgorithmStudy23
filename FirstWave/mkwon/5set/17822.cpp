#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,k,res=0,numcnt=0,tab[55][55]={0,};

void loop(int x,int y,int z){
    int j=1,idx=x;;
    while(1){
        idx=x*j;
        j++;
        if (idx>n) break;

        int temp[55]={0,};
        if (y==0){
            for(int i=1; i<=m; i++){
                int newidx = i+z;
                if (newidx>m) newidx=newidx-m;
                temp[newidx]=tab[idx][i];
            }
            for(int i=1; i<=m; i++)
                tab[idx][i]=temp[i];
        }
        else{
            for(int i=1; i<=m; i++){
                int newidx = i-z;
                if (newidx<=0) newidx=newidx+m;
                temp[newidx]=tab[idx][i];
            }
            for(int i=1; i<=m; i++)
                tab[idx][i]=temp[i];
        }
    }
}

void sum(){
    res=0; numcnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            res+=tab[i][j];
            if (tab[i][j]>0) numcnt++;
        }
    }
}

void deletedup(){

    int flag=0,temp[55][55]={0,};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int num = tab[i][j];
            if (i!=1 && tab[i-1][j]!=0 && tab[i][j]!=0 && tab[i-1][j]==tab[i][j]){
                temp[i-1][j]=1; temp[i][j]=1; flag=1;
            }
            if (j!=1 && tab[i][j-1]!=0 && tab[i][j]!=0 && tab[i][j-1]==tab[i][j]){
                temp[i][j-1]=1; temp[i][j]=1; flag=1;
            }
            if (i!=n && tab[i+1][j]!=0 && tab[i][j]!=0 && tab[i+1][j]==tab[i][j]){
                temp[i+1][j]=1; temp[i][j]=1; flag=1;
            }
            if (j!=m && tab[i][j+1]!=0 && tab[i][j]!=0 && tab[i][j+1]==tab[i][j]){
                temp[i][j+1]=1; temp[i][j]=1; flag=1;
            }
            if ((j==1 || j==m) && tab[i][1]!=0 && tab[i][m]!=0 && tab[i][1]==tab[i][m]){
                temp[i][1]=1; temp[i][m]=1; flag=1;
            }
        }
    }

    if(!flag){
        sum();
        double avg= (double)res/numcnt;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if ((double)tab[i][j]>avg) tab[i][j]--;
                else if (tab[i][j]!=0 && (double)tab[i][j]<avg) tab[i][j]++;
            }
        }
        return ;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (temp[i][j]) tab[i][j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>tab[i][j];
        }
    }

    while(k--){
        int x,y,z;
        cin>>x>>y>>z;
        loop(x,y,z);
        deletedup();
    }

    sum();
    cout<<res;;

    return 0;
}
