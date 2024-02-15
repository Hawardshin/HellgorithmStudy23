#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int a, b, c, d;
queue<pair<int, int>> q;
set<int> vis[100005];

void check(int nx, int ny) {
    if (vis[nx].find(ny) == vis[nx].end()) {
        q.push({nx, ny});
        vis[nx].insert(ny);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    int cnt = 0;
    q.push({0, 0});
    vis[0].insert(0);
    while (!q.empty()) {
        int t = q.size();
        while (t--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == c && y == d) {
                cout << cnt;
                return 0;
            }

            check(a, y);
            check(x, b);
            check(0, y);
            check(x, 0);
            check(x - min(b - y, x), min(x + y, b));
            check(min(x + y, a), y - min(a - x, y));
        }
        cnt++;
    }
    cout << "-1";

    return 0;
}
