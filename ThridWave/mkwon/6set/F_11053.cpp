#include <algorithm>
#include <iostream>

using namespace std;

int n, arr[1005], dp[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    fill(dp, dp + n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > res) res = dp[i];
    }
    cout << res;

    return 0;
}
