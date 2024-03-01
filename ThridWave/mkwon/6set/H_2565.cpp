#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, dp[105];
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    fill(dp, dp + n, 1);
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (res < dp[i]) res = dp[i];
    }
    cout << n - res;

    return 0;
}
