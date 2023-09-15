#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

string s1,s2;
queue <char> q;
vector <char> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>s1>>s2;

    for(int i=0; i<s1.size(); i++){
        v.push_back(s1[i]);
        if (v.size() >= s2.size()){
            int cnt=0;
            for(int j=s2.size()-1,k=v.size()-1; j>=0; j--,k--){
                if (s2[j]==v[k]) cnt++;
                else break;
            }
            if (cnt == s2.size()) v.erase(v.end()-s2.size(), v.end());
        }
    }

    if (!v.size()) cout<<"FRULA";
    else{
        for(int i=0; i<v.size(); i++) cout<<v[i];
    }

    return 0;
}