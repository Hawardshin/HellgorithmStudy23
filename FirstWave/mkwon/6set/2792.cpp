#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, v[300005], ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v, v+m);

    int left = 1, right = v[m - 1];
    while (left<=right) {
        int mid = (left + right) / 2;
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += v[i] / mid;
            if (v[i] % mid != 0) cnt++;
        }

        if (cnt <= n) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;

}