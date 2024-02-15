#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, dp[100005][7][7];

int point(int x, int y) {
    // 연속 : 1
    // 중앙 : 2
    // 인접 : 3
    // 반대 : 4
    if (x == y) return 1;
    if (x == 0) return 2;
    if (abs(x - y) == 1 || abs(x - y) == 3) return 3;
    if (abs(x - y) == 2) return 4;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1;; i++) {
        int a;
        cin >> a;
        if (a == 0) break;
        n = i;
        for (int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 4; k++) {
                if (dp[i - 1][j][k] >= INF) continue;

                int x = point(j, a);
                int y = point(k, a);

                dp[i][j][a] = min(dp[i][j][a], dp[i - 1][j][k] + y);
                dp[i][a][k] = min(dp[i][a][k], dp[i - 1][j][k] + x);
            }
        }
    }

    int res = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res = min(res, dp[n][i][j]);
        }
    }
    cout << res;

    return 0;
}