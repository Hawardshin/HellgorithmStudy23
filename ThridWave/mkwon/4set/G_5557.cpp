#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, arr[105];
long long dp[105][25];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][arr[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j]) {
                if (j + arr[i] <= 20) {
                    dp[i][j + arr[i]] += dp[i - 1][j];
                }
                if (j - arr[i] >= 0) {
                    dp[i][j - arr[i]] += dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[n - 2][arr[n - 1]];

    return 0;
}