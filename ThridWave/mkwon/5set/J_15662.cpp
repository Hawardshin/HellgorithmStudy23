#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

int t, k;
deque<int> dq[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        char c[10];
        for (int j = 0; j < 8; j++) {
            cin >> c[j];
            dq[i].push_back(c[j] - '0');
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        int vis[1001];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q, qq;

        q.push({a - 1, b});
        qq.push({a - 1, b});
        vis[a - 1] = 1;

        while (!q.empty()) {
            int idx = q.front().first;
            int d = q.front().second;
            q.pop();

            if (idx != 0) {  // 왼
                if (vis[idx - 1] == 0 && dq[idx][6] != dq[idx - 1][2]) {
                    vis[idx - 1] = 1;
                    q.push({idx - 1, d * -1});
                    qq.push({idx - 1, d * -1});
                }
            }
            if (idx != t - 1) {  // 오
                if (vis[idx + 1] == 0 && dq[idx][2] != dq[idx + 1][6]) {
                    vis[idx + 1] = 1;
                    q.push({idx + 1, d * -1});
                    qq.push({idx + 1, d * -1});
                }
            }
        }

        while (!qq.empty()) {
            int idx = qq.front().first;
            int d = qq.front().second;
            qq.pop();

            if (d == 1) {  // 시계
                int temp = dq[idx].back();
                dq[idx].pop_back();
                dq[idx].push_front(temp);
            } else if (d == -1) {  // 반시계
                int temp = dq[idx].front();
                dq[idx].pop_front();
                dq[idx].push_back(temp);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < t; i++) {
        if (dq[i][0] == 1) res++;
    }
    cout << res;

    return 0;
}