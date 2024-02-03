#include <iostream>
#include <queue>

using namespace std;

int n, k, vis[200005], res, cnt[200005];
queue<pair<int, int>> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    fill(vis, vis + 100005, -1);

    q.push({n, 0});
    vis[n] = 0;
    cnt[n] = 1;
    while (!q.empty()) {
        int idx = q.front().first;
        int time = q.front().second;
        q.pop();

        if (idx < 100000 && vis[idx * 2] == -1) {
            vis[idx * 2] = vis[idx] + 1;
            cnt[idx * 2] = cnt[idx];
            q.push({idx * 2, time + 1});
        } else if (idx < 100000 && vis[idx * 2] == vis[idx] + 1) {
            cnt[idx * 2] += cnt[idx];
        }

        if (idx > 0 && vis[idx - 1] == -1) {
            vis[idx - 1] = vis[idx] + 1;
            cnt[idx - 1] = cnt[idx];
            q.push({idx - 1, time + 1});
        } else if (idx > 0 && vis[idx - 1] == vis[idx] + 1) {
            cnt[idx - 1] += cnt[idx];
        }

        if (idx < 100000 && vis[idx + 1] == -1) {
            vis[idx + 1] = vis[idx] + 1;
            cnt[idx + 1] = cnt[idx];
            q.push({idx + 1, time + 1});
        } else if (idx < 100000 && vis[idx + 1] == vis[idx] + 1) {
            cnt[idx + 1] += cnt[idx];
        }
    }

    cout << vis[k] << "\n" << cnt[k];

    return 0;
}
