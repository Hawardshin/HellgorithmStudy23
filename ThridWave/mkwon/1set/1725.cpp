#include <iostream>
#include <stack>

using namespace std;

int n, res=0;
int tab[100005]={0,};
stack <int> s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>tab[i];
    }
    tab[0]=0;
    
    s.push(0);
    for (int i=1; i<=n+1; i++){
        // 직사각형
        while (!s.empty() && tab[s.top()] > tab[i]){
            int top = s.top();
            s.pop();

            // cout<<"i : "<<i<<", top : "<<top<<"\n";
            // cout<<"new : "<<(i -top) * tab[top]<<", res : "<<res<<"\n";

            res = max((i - 1 - s.top()) * tab[top], res);
        }
        s.push(i);
    }
    cout<<res;

    return 0;
}

// 긴 시작점 push
// 이 전 막대보다 작다면 -> 직사각형 계산 -> while !!!
// i - 1 - s.top()) * tab[top]
// 현재막대 앞 ~ 전 막대 길이 * 직사각형높이