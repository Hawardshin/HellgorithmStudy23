#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n,m;
int num[1005]={0,};

stack <int> s;

int main(){

    cin>>n;
    for(int i=0; i<n; i++) cin>>num[i];

    int flag=0;
    for(int i=0,cnt=1; ;){
        if(s.empty() && i==n) break;

        if (num[i] == cnt){
            cnt++; i++; continue;
        }
        else if (!s.empty() && s.top() == cnt){
            cnt++; s.pop(); continue;
        }
        else if (!s.empty() && s.top() < num[i]){
            flag=1; break;
        }
        else{
            s.push(num[i]); i++;
        }
    }

    if (!s.empty() || flag) cout<<"Sad";
    else cout<<"Nice";

    return 0;
}