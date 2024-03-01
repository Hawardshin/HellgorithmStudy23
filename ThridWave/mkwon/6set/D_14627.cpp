#include <algorithm>
#include <iostream>

using namespace std;

long long s, n;
long long pa[1000005], res = 0, sum = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;
    for (int i = 0; i < s; i++) {
        cin >> pa[i];
        sum += pa[i];
    }

    long long left = 1, right = 1000000000;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;

        for (int i = 0; i < s; i++) {
            cnt += pa[i] / mid;
        }

        if (cnt >= n) {
            left = mid + 1;
            res = mid;
        } else
            right = mid - 1;
    }
    cout << sum - res * n;

    return 0;
}
