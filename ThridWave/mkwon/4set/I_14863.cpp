#include <algorithm>
#include <iostream>

using namespace std;

int n, k, dp[105][100005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (i == 1) {
            dp[i][a] = b;
            dp[i][c] = max(dp[i][c], d);
        } else {
            for (int j = 0; j <= k; j++) {
                if (dp[i - 1][j] != 0) {
                    if (j + a <= k) dp[i][j + a] = max(dp[i][j + a], dp[i - 1][j] + b);
                    if (j + c <= k) dp[i][j + c] = max(dp[i][j + c], dp[i - 1][j] + d);
                }
            }
        }
    }

    int res = -1;
    for (int i = 1; i <= k; i++) res = max(res, dp[n][i]);
    cout << res;

    return 0;
}
