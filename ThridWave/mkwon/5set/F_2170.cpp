#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int left = v[0].first, right = v[0].second, res = 0;
    for (int i = 1; i < n; i++) {
        if (right < v[i].first) {
            res += right - left;
            left = v[i].first;
            right = v[i].second;
        } else {
            if (right < v[i].second) right = v[i].second;
        }
    }
    res += right - left;
    cout << res;

    return 0;
}