#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1 == s2){
        cout<<"1";
        return 0;
    }
    if (s1.size() < s2.size()){
        cout<<"0";
        return 0;
    }

    int cnt = 0;
    for (int i=0; i<=s1.size()-s2.size(); i++){
        int flag = 1;
        for (int j=0,k=i; j<s2.size() && k<s1.size(); j++,k++){
            if (s1[k] != s2[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            cnt++;
            i += s2.size() - 1;
        }
    }

    cout<<cnt;

    return 0;
}
