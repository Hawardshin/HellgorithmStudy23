#include <iostream>
#include <algorithm>

using namespace std;

int k,len=1,node[1028]={0,},deepres[1028]={0,};

void loop(int num, int deep){
    deepres[num]=deep;

    if (deep == k) return ;
    loop((num-1)/2+1, deep+1);
    loop((num+len+1)/2, deep+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>k;
    for (int i=0; i<k; i++) len*=2;
    len--;

    for (int i=1; i<=len; i++)
        cin>>node[i];

    loop(len/2+1, 1);

    for (int i=1; i<=k; i++){
        for(int j=1; j<=len; j++){
            if (deepres[j] == i) cout<<node[j]<<" ";
        } cout<<"\n";
    }

    return 0;
}
