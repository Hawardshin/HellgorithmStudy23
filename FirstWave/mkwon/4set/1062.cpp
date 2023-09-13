#include <iostream>
#include <algorithm>

using namespace std;

int n,m,res=0,maxlen=0;
string str;
vector <char> alpha,vec[52],group;

void loop(int x){
    if (group.size()==m-5 || group.size()==maxlen){
        int cnt = 0;
        for (int i=0; i<n; i++){
            int temp = 0;
            for(int j=0; j<vec[i].size(); j++){
                if (find(group.begin(), group.end(), vec[i][j]) == group.end()) break;
                else temp++;
            }
            if (temp == vec[i].size()) cnt++;
        }
        if (cnt>res) res=cnt;
    }

    for (int i=x; i<alpha.size(); i++){
        if (find(group.begin(), group.end(), alpha[i]) != group.end()) continue;
        group.push_back(alpha[i]);
        loop(i);
        group.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>str;
        int templen=0;
        for(int j=4; j<str.size()-4; j++){
            if(str[j]=='a' || str[j]=='n' || str[j]=='t' || str[j]=='i' || str[j]=='c') continue;
            if (find(alpha.begin(), alpha.end(), str[j]) == alpha.end())
                alpha.push_back(str[j]);
            vec[i].push_back(str[j]);
            templen++;
        }
        if (templen>maxlen) maxlen=templen;
    }
    if (maxlen>m-5) maxlen=m-5;

    if(m<5){ cout<<"0"; return 0; }
    if(alpha.size()<=m-5) { cout<<n; return 0; }
    loop(0);
    cout<<res;

    return 0;
}
