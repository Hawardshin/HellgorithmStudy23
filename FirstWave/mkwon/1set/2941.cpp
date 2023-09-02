#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    cin>>s1;
    
    int cnt = s1.size();
    for (int i=0; i<s1.size(); i++){
        if (s1[i] == '='){
            if (s1[i-1] == 'c')
                cnt--;
            else if (s1[i-1] == 's')
                cnt--;
            else if (s1[i-1] == 'z' && i >= 2 && s1[i-2] == 'd')
                cnt-=2;
            else if (s1[i-1] == 'z')
                cnt--;
        }
        else if (s1[i] == '-'){
            if (s1[i-1] == 'c')
                cnt--;
            else if (s1[i-1] == 'd')
                cnt--;
        }
        else if (s1[i] == 'j'){
            if (s1[i-1] == 'l')
                cnt--;
            else if (s1[i-1] == 'n')
                cnt--;
        }
    }

    cout<<cnt;

    return 0;
}