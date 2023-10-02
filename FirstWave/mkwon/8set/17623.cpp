#include <iostream>
#include <algorithm>
using namespace std;

int t,n,res;
string dp[1005];

string mycompare(string a, string b){
    if(b=="-1") return a;
    if(a.size() < b.size()) return a;
    if(a.size() > b.size()) return b;
    return min(a,b);
}

void loop(){
    for(int i=1; i<=1000; i++) dp[i]="-1";
    dp[1]="12"; dp[2]="34"; dp[3]="56";

    for(int i=4; i<=1000; i++){
        if(i%2==0){
            string s = "1"+dp[i/2]+"2";
            dp[i]=mycompare(s,dp[i]);
        }
        if(i%3==0){
            string s = "3"+dp[i/3]+"4";
            dp[i]=mycompare(s,dp[i]);
        }
        if(i%5==0){
            string s = "5"+dp[i/5]+"6";
            dp[i]=mycompare(s,dp[i]);
        }

        for(int j=1; j<i; j++){
            string s = dp[i-j]+dp[j];
            dp[i]=mycompare(s,dp[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>t;
    loop();
    while(t--){
        cin>>n;
        for(int i=0; i<dp[n].size(); i++){
            if (dp[n][i]=='1') cout<<"(";
            if (dp[n][i]=='2') cout<<")";
            if (dp[n][i]=='3') cout<<"{";
            if (dp[n][i]=='4') cout<<"}";
            if (dp[n][i]=='5') cout<<"[";
            if (dp[n][i]=='6') cout<<"]";
        }
        cout<<"\n";
    }

    return 0;
}
