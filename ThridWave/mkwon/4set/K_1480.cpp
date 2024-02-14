#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int N, M, C;
int jewel[15];
int dp[12][1 << 13][22];  // [현재가방][챙긴보석][남은한도]

int solve(int cur, int visited, int capacity) {
    if (cur == M) {
        return 0;
    }

    if (dp[cur][visited][capacity] != 0) {
        return dp[cur][visited][capacity];
    }

    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) {
            continue;
        }

        if (capacity < jewel[i]) {
            dp[cur][visited][capacity] = max(dp[cur][visited][capacity], solve(cur + 1, visited, C));
        } else {
            dp[cur][visited][capacity] = max(dp[cur][visited][capacity], solve(cur, visited | (1 << i), capacity - jewel[i]) + 1);
        }
    }

    return dp[cur][visited][capacity];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> C;

    for (int i = 0; i < N; i++) {
        cin >> jewel[i];
    }

    cout << solve(0, 0, C);

    return 0;
}
