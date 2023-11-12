#include <iostream>
#define MAX 9
using namespace std;

int s[MAX], w[MAX];
int n, answer;

void dfs(int idx) {
    
    // 계란 다 잡음
    if(idx == n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] <= 0) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }
    
    // 지금거 계란 깨짐
    if(s[idx] <= 0) dfs(idx + 1);
    else {
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(idx == i || s[i] <= 0) continue;
            s[idx] -= w[i]; // 계란 내구도
            s[i] -= w[idx]; // 내구도 적용
            flag = true; // 깨짐
            dfs(idx + 1);
            s[i] += w[idx];
            s[idx] += w[i];
        }

        if(!flag) dfs(n);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s[i]>>w[i];
    }
    dfs(0);
    cout<<answer;
}