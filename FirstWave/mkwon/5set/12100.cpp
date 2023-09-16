#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int n,tab[25][25]={0,},res=0;

void move(int arr[][25]){
    for(int i=0; i<n; i++) {
        deque <int> dq;
        bool isAlreadyMerge = false;

        for(int j=0; j<n; j++) {
            if(arr[i][j]!=0) {
                if(!dq.empty() && dq.back()==arr[i][j] && isAlreadyMerge==false){
                    dq.pop_back();
                    dq.push_back(arr[i][j]*2);
                    isAlreadyMerge=true;
                }else{
                    dq.push_back(arr[i][j]);
                    isAlreadyMerge=false;
                }
                arr[i][j]=0;
            }
        }

        int index = 0;
        while(!dq.empty()){
            arr[i][index++] = dq.front();
            dq.pop_front();
        }
    }
}

void rotation(int arr[][25]){
    int temp[25][25];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            temp[j][n-1-i] = arr[i][j];
    memcpy(arr,temp,sizeof(temp));
}

void dfs(int cnt){
    if(cnt == 5) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if(res<tab[i][j]) res=tab[i][j];
            }
        }
        return;
    }

    int temp[25][25];
    for(int i = 0; i < 4; i++) {
        memcpy(temp, tab, sizeof(tab)); // origin->copy
        move(tab);
        dfs(cnt+1);
        memcpy(tab, temp, sizeof(tab)); // copy->origin
        rotation(tab);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab[i][j];
        }
    }

    dfs(0);
    cout<<res;

    return 0;
}
