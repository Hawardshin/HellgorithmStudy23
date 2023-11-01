#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int dong[15];
int num[3][8];
char flag[3];
int copyDong[15];

void init(int n, int testnum){
    for(int i=1; i<=12; i++){
        if (i == n) copyDong[i]=testnum;
        else copyDong[i]=2;
    }
}

int check(){
    int cnt=0;
    for (int t=0; t<3; t++){
        int left=0, right=0;
        for(int i=0; i<4; i++) left += copyDong[num[t][i]];

         for(int i=4; i<8; i++) right += copyDong[num[t][i]];
    
        if (flag[t]=='>'){
            if (left > right) cnt++;
        }
        else if (flag[t]=='<'){
            if (left < right) cnt++;
        }
        else{
            if (left == right) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int t=0; t<3; t++){

        for(int i=0; i<4; i++)
            cin>>num[t][i];
        cin>>flag[t];
        for(int i=4; i<8; i++)
            cin>>num[t][i];
        
        if (flag[t] == '='){
            for(int i=0; i<8; i++){
                dong[num[t][i]]=2;
            }
        } else {
            for(int i=1; i<=12; i++){
                int *p;
                p = find(num[t], num[t]+8, i);
                if (p == num[t]+8){
                    dong[i]=2;
                }
            }
        }

    }
    
    // for(int i=1; i<=12; i++){
    //     cout<<dong[i]<<" ";
    // } cout<<"\n";

    int ppp=0;
    for(int i=1; i<=12; i++){
        if (dong[i] != 2) ppp++;
    }
    if (ppp == 0){
        cout<<"impossible";
        return 0;
    }

    int resCount=0;
    int resI; char resC;
    for(int i=1; i<=12; i++){
        int temp;
        if (dong[i] != 2){
            init(i, 1);
            temp = check();
            if (temp == 3){
                resI=i; resC='-';
                // cout<<i<<"-";
                resCount++;
            }
            init(i, 3);
            temp = check();
            if (temp == 3){
                resI=i; resC='+';
                // cout<<i<<"+";
                resCount++;
            }
        }
    }

    if (resCount == 1){
        cout<<resI<<resC;
    }
    else {
        cout<<"indefinite";
    }
    
    return 0;
}

// 모든 동전이 2, 모조품은 1이거나 3