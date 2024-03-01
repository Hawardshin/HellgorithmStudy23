#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int n, m, narr[1000005], marr[1000005];
        set<int> s;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (s.find(x) != s.end())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}
