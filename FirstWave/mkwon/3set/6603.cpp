#include <iostream>
#include <algorithm>

using namespace std;

int k,num[15]={0,},res[10]={0,};

void loop(int x, int cnt){
    if (cnt == 6){
        for (int i=0; i<6; i++) 
            cout<<res[i]<<" ";
        cout<<"\n";
        return ;
    }

    for (int i=x; i<k; i++){
        res[cnt] = num[i];
        loop(i+1,cnt+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while(1){
        cin>>k;
        if (k==0) break;
        for (int i=0; i<k; i++) cin>>num[i];
        loop(0,0);
        cout<<"\n";
    }
    return 0;
}
