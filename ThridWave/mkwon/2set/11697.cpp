#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, vis[105][105], on[105][105], res;
vector<pair<int, int>> v[105][105];
queue<pair<int, int>> q, visq;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[a][b].push_back({c, d});
    }

    q.push({1, 1});
    visq.push({1, 1});
    vis[1][1] = 1;
    on[1][1] = 1;
    res = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < v[x][y].size(); i++) {
            int nx = v[x][y][i].first;
            int ny = v[x][y][i].second;
            if (on[nx][ny] == 0) {
                on[nx][ny] = 1;
                res++;
            }
        }

        int t = visq.size();
        while (t--) {
            int x = visq.front().first;
            int y = visq.front().second;
            visq.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx <= n && ny >= 0 && ny <= n) {
                    if (on[nx][ny] == 1 && vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        visq.push({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
            visq.push({x, y});
        }
    }
    cout << res;

    return 0;
}