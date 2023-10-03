#include <iostream>
#include <algorithm>

using namespace std;

int T,N;
string bracket[1001];
string change = " (){}[]";
string compare(string a,string b){
    if (b == "")
        return a;
    if(a.length() < b.length()) 
        return a;
    if(a.length() > b.length()) 
        return b;
    return min(a,b);
}

void dp(){
    bracket[1] = "12";
    bracket[2] = "34";
    bracket[3] = "56";

    for(int i=4;i<=1000;i++) { // 해당 i의 최솟값 문자열 갱신
        string s;
        if(i % 2 == 0) // 감쌀때
            bracket[i] = compare("1" + bracket[i / 2] + "2", bracket[i]);
        if(i % 3 == 0)
            bracket[i] = compare("3" + bracket[i / 3] + "4", bracket[i]);
        if(i % 5 == 0)
            bracket[i] = compare("5" + bracket[i / 5] + "6", bracket[i]);
        
        for(int j = 1; j < i; j++) // 두 문자열 더할때
            bracket[i] = compare(bracket[i - j] + bracket[j], bracket[i]);
    }
}

int main(){
    cin >> T;
    dp();
    while(T--){
        cin >> N;

        string ret = bracket[N];
        int len = ret.length();
        for (int i = 0; i < len; i++)
        {
            cout << change[ret[i] - '0'];
        }
        cout << endl;
    }
}
