#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t=0;
    while(1){
        t++;
        string str;
        cin>>str;

        if (str.find('-') != std::string::npos) break;

        stack <char> s;
        if (str.length() == 0){
            cout<<t<<". 0\n";
            continue;
        }
         s.push(str[0]);
        for(int i=1; i<str.length(); i++){
            if (str[i] == '}'){
                if (!s.empty() && s.top() == '{') s.pop();
                else s.push(str[i]);
            }
            else s.push(str[i]);
        }

        // {{,}} 연속 -> 하나만 바꿔도 됨
        int res=0;
        while(!s.empty()){
            int c = s.top();
            s.pop();
            if (!s.empty()){
                if (s.top() == c){
                    s.pop();
                    res++;
                    continue;
                }
            }
            res++;
        }

        cout<<t<<". "<<res<<"\n";


    }
    
    return 0;
}
