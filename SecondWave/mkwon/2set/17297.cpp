#include <iostream>
#include <algorithm>

using namespace std;

int n;
string str1 = "Messi";
string str2 = "Messi Gimossi";
string str;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

    if (n<=5) {
        cout<<str1[n-1];
        return 0;
    }
    else if (n<=13){
        cout<<str2[n-1];
        return 0;
    }
    
    int last1=5,last2=13;
    int newN;
    while (1){
        newN = last1+last2+1;
        str = str1+" "+str2;
        if (newN > n) break;
        else {
            last1 = last2;
            str1=str2;
            last2 = newN;
            str2=str;
        }
    }
    if (str[n-1] == ' ') cout<<"Messi Messi Gimossi";
    else cout<<str[n-1];
    
    return 0;
}

// 1 5 (Messi)
// 2 13 (Messi Gimossi)
// 3 19 (13 + 1 + 5)
// 4 33 (19 + 1 + 13)
// 5 51 (33 + 1 + 19)