#include <iostream>
#include <queue>

using namespace std;

int n, m, vis[305][305];
char tab[305][305];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q, nextq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    nextq.push({a - 1, b - 1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
        }
    }

    int res = 0;
    while (1) {
        q = nextq;
        while (!nextq.empty()) nextq.pop();
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (vis[nx][ny]) continue;

                    if (tab[nx][ny] == '1') {
                        vis[nx][ny] = 1;
                        tab[nx][ny] = '0';
                        nextq.push({nx, ny});
                    } else if (tab[nx][ny] == '0') {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    } else if (tab[nx][ny] == '#') {
                        cout << res + 1;
                        return 0;
                    }
                }
            }
        }
        res++;
    }

    return 0;
}
