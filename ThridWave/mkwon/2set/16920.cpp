#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, p;
long long num[1005];
char tab[1005][1005];
queue<pair<int, int>> q[10], qq;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
            if (tab[i][j] >= '1' && tab[i][j] <= '9') {
                q[tab[i][j] - '0'].push({i, j});
            }
        }
    }

    while (1) {
        int cnt = 0;

        for (int i = 1; i <= p; i++) {
            if (q[i].empty()) {
                cnt++;
                continue;
            }
            while (!q[i].empty()) {
                int x = q[i].front().first;
                int y = q[i].front().second;
                q[i].pop();

                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (tab[nx][ny] == '.') {
                            tab[nx][ny] = '0' + i;
                            qq.push({nx, ny});
                        }
                    }
                }
            }

            for (int j = 2; j <= num[i]; j++) {
                int t = qq.size();
                if (t == 0) break;
                while (t--) {
                    int x = qq.front().first;
                    int y = qq.front().second;
                    qq.pop();

                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (tab[nx][ny] == '.') {
                                tab[nx][ny] = '0' + i;
                                qq.push({nx, ny});
                            }
                        }
                    }
                }
            }

            while (!qq.empty()) {
                q[i].push(qq.front());
                qq.pop();
            }
        }

        if (cnt == p) break;
    }

    for (int k = 0; k < p; k++) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tab[i][j] == '1' + k) res++;
            }
        }
        cout << res << " ";
    }

    return 0;
}