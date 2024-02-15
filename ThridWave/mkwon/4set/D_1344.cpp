#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
double A, A_, B, B_, dp[20][20][20];

bool is_prime(int n) {
    if (n == 0 or n == 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

double dfs(int idx, int a, int b) {
    if (idx == 18) {
        if (is_prime(a) or is_prime(b))
            return 1;
        else
            return 0;
    }
    if (dp[idx][a][b]) return dp[idx][a][b];

    dp[idx][a][b] += dfs(idx + 1, a, b) * A_ * B_;
    dp[idx][a][b] += dfs(idx + 1, a, b + 1) * A_ * B;
    dp[idx][a][b] += dfs(idx + 1, a + 1, b) * A * B_;
    dp[idx][a][b] += dfs(idx + 1, a + 1, b + 1) * A * B;

    return dp[idx][a][b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    A *= 0.01;
    B *= 0.01;
    A_ = 1 - A;
    B_ = 1 - B;
    cout << dfs(0, 0, 0);
}