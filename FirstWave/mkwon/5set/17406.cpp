#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 2147483647

typedef struct {
    int r;
    int c;
    int s;
} pos;

vector <pos> v;
vector <int> seq;
int n,m,k,res=INF,tab1[105][105]={0,},tab2[105][105]={0,},vis[105]={0,};

void spin(int r, int c, int s){
    while (s){
        int temp = tab2[r-s][c-s];
        for (int i=r-s+1; i<=r+s; i++) tab2[i-1][c-s]=tab2[i][c-s];
        for (int i=c-s+1; i<=c+s; i++) tab2[r+s][i-1]=tab2[r+s][i];
        for (int i=r+s-1; i>=r-s; i--) tab2[i+1][c+s]=tab2[i][c+s];
        for (int i=c+s-1; i>=c-s; i--) tab2[r-s][i+1]=tab2[r-s][i];
        tab2[r-s][c-s+1]=temp;
        s--;
    }
}

int check(){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            tab2[i][j]=tab1[i][j];
        }
    }

    for(int i=0; i<k; i++){
        pos p = v[seq[i]];
        spin(p.r,p.c,p.s);
    }

    int minsum=INF;
    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=m; j++){
            sum+=tab2[i][j];
        }
        if (minsum>sum) minsum=sum;
    }

    return minsum;
}

void loop(int x){

    if (x == k){
        int temp = check();
        if (temp<res) res=temp;
        return ;
    }

    for(int i=0; i<k; i++){
        if (vis[i]) continue;
        vis[i]=1;
        seq.push_back(i);
        loop(x+1);
        vis[i]=0;
        seq.pop_back();
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>tab1[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int x,y,z;
        cin>>x>>y>>z;
        pos p; p.r=x; p.c=y; p.s=z;
        v.push_back(p);
    }

    loop(0);
    cout<<res;

    return 0;
}