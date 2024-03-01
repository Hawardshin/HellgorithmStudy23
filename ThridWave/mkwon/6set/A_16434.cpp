#include <algorithm>
#include <iostream>

using namespace std;

typedef tuple<int, int, int> t;

int n, m;
vector<t> v;
long long res;

bool check(long long HP) {
    long long atk = m, hp = HP;

    for (int i = 0; i < n; i++) {
        int state, ma, mh;
        tie(state, ma, mh) = v[i];

        if (state == 1) {
            long long t;

            if (mh % atk == 0)
                t = mh / atk - 1;
            else
                t = mh / atk;

            hp -= ma * t;
            if (hp <= 0) return false;
        } else {
            atk += ma;
            hp = min(HP, hp + mh);
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    long long left = 1, right = 1e18;
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid)) {
            right = mid - 1;
            res = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << res;

    return 0;
}
