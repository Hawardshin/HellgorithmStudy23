#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int tc, N;
long long dp[101] = {
    0, 0, 1, 7, 4, 2, 6, 8, 10,
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tc;

    for (int i = 9; i < 101; i++) {
        dp[i] = 9e20;

        for (int j = 2; j <= 7; j++) {
            long long v = dp[i - j] * 10;
            if (j != 6) v += dp[j];
            dp[i] = min(dp[i], v);
        }
    }

    while (tc--) {
        cin >> N;
        string maxv;
        cout << dp[N];
        if (N % 2 == 0) {
            // 짝수 : 1배치, 가장 작은 수
            for (int i = 0; i < N / 2; i++) maxv += '1';
        } else {
            // 홀수 : 7배치, 가장 큰 수
            maxv += '7';
            for (int i = 0; i < N / 2 - 1; i++) maxv += '1';
        }

        cout << ' ' << maxv << '\n';
    }

    return 0;
}