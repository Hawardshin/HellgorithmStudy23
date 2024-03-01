#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, arr[1005], dp[1005];
vector<int> v;

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
    int temp = res;
    for (int i = n - 1; i >= 0; i--) {
        if (temp == 0) break;
        if (dp[i] == temp) {
            v.push_back(arr[i]);
            temp--;
        }
    }

    cout << res << "\n";
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";

    return 0;
}
