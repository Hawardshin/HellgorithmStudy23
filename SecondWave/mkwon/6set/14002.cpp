#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int num[1005]={0,},res[1005]={0,};
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num[i];
        res[i]=1;
    }

    for(int i=0; i<n; i++){
        int temp = 1;
        for(int j=0; j<i; j++){
            if(num[i] > num[j]){
                if (temp < res[j] + 1)
                    temp = res[j] + 1;
            }
        }
        res[i]=temp;
    }

    int ans=0,temp=0;;
    for(int i=0; i<n; i++){
        if(res[i] > ans) ans=res[i];
    }
    cout<<ans<<"\n";
    temp=ans;
    for(int i=n-1; i>=0; i--){
        if (res[i] == ans){
            v.push_back(num[i]);
            ans--;
        }
    }

    for(int i=temp-1; i>=0; i--){
        cout<<v[i]<<" ";
    }
    
    return 0;
}

// 6
// 1 2 1 3 2 5 