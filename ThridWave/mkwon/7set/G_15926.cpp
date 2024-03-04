#include <iostream>
#include <stack>

using namespace std;

int n, ret = -987654321, dp[200004];
string str;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(')
            s.push(i);
        else if (!s.empty() and str[i] == ')') {
            int idx = s.top();
            dp[idx] = 1;
            dp[i] = 1;
            s.pop();
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 1)
            cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }

    cout << max(ret, cnt);

    return 0;
}