#include <iostream>
#include <queue>

using namespace std;

int n, k;
int vis[500005][2];
queue<pair<int, int>> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    q.push({n, 0});
    vis[n][0] = 0;
    while (!q.empty()) {
        int idx = q.front().first;
        int time = q.front().second;
        q.pop();

        int sum = time * (time + 1) / 2;
        if (k + sum > 500000) continue;
        if (idx == k + sum || vis[k + sum][time % 2] == 1) {
            cout << time;
            return 0;
        }

        if (idx * 2 <= 500000 && vis[idx * 2][(time + 1) % 2] == 0) {
            vis[idx * 2][(time + 1) % 2] = 1;
            q.push({idx * 2, time + 1});
        }
        if (idx > 0 && vis[idx - 1][(time + 1) % 2] == 0) {
            vis[idx - 1][(time + 1) % 2] = 1;
            q.push({idx - 1, time + 1});
        }
        if (idx < 500000 && vis[idx + 1][(time + 1) % 2] == 0) {
            vis[idx + 1][(time + 1) % 2] = 1;
            q.push({idx + 1, time + 1});
        }
    }
    cout << "-1";

    return 0;
}

// 8725 328744
// -1
// -> 589
// 34768 292340
// -1
// -> segmentation fault