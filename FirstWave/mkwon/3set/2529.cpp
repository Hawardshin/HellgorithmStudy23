#include <iostream>
#include <algorithm>

using namespace std;

int k,res[12]={0,},vis[12]={0,},flag=0;
long maxres=0, minres=9876543219;
char sign[12];

void maxminres(){
    long temp = 0;
    for (int i=0; i<=k; i++)
        temp = temp*10 + res[i];
    if (temp > maxres) maxres = temp;
    if (temp < minres){
        minres = temp;
        if (res[0] == 0) flag = 1;
        else flag = 0;
    } 
}

int check(){
    for (int i=0; i<k; i++){
        if (sign[i] == '<'){
            if (res[i] > res[i+1]) return 0;
        }
        else{
            if (res[i] < res[i+1]) return 0;
        }
    }
    return 1;
}

void loop(int x, int cnt){

    if (cnt == k + 1){
        if (!check()) return ;
        maxminres();
        return ;
    }

    for (int i=0; i<=9; i++){
        if (vis[i] == 1) continue;
        vis[i] = 1;
        res[cnt] = i;
        loop(i, cnt+1);
        vis[i] = 0;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>k;
    for (int i=0; i<k; i++) cin>>sign[i];

    loop(0,0);
    cout<<maxres<<"\n";
    if (flag) cout<<"0";
    cout<<minres;

    return 0;
}