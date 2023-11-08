#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

string str,res="";

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>str;

    int len=0,flag=0;
    for (int i=0; i<str.length(); i++){
        // cout<<res<<"\n";

        if (str[i] == '.'){
            res.append(".");
            continue;
        }
        else len++;

        if (str[i+1] == '\0' || str[i+1] == '.'){
            while (len > 0){
                if (len >= 4){
                    res.append("AAAA");
                    len-=4;
                }
                else if (len >= 2){
                    res.append("BB");
                    len-=2;
                }
                else {
                    flag=1;
                    break;
                }
            }
            if (flag==1 || len!=0)
                break;
        }
    }

    if (flag == 1) cout<<"-1";
    else cout<<res;

    
    return 0;
}