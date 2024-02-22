#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, tab[10][10], res = 987654321;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};  // 상 좌 하 우
vector<pair<int, int>> v;

void cctv(int x, int y, int dir) {
    if (dir > 3) dir = dir % 4;
    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        if (nx < 0 || ny < 0 || nx >= n || ny >= m || tab[nx][ny] == 6) return;
        if (tab[nx][ny] >= 1 && tab[nx][ny] <= 5) continue;

        tab[nx][ny] = -1;  // # 대체
    }
}

void dfs(int idx) {
    if (idx == v.size()) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tab[i][j] == 0) sum++;
            }
        }
        if (sum < res) res = sum;
        return;
    }

    int x = v[idx].first;
    int y = v[idx].second;

    for (int dir = 0; dir < 4; dir++) {
        // 백업
        int backup[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backup[i][j] = tab[i][j];
            }
        }

        // 방향별 탐색
        if (tab[x][y] == 1) {
            cctv(x, y, dir);
        } else if (tab[x][y] == 2) {
            cctv(x, y, dir);
            cctv(x, y, dir + 2);
        } else if (tab[x][y] == 3) {
            cctv(x, y, dir);
            cctv(x, y, dir + 1);
        } else if (tab[x][y] == 4) {
            cctv(x, y, dir);
            cctv(x, y, dir + 1);
            cctv(x, y, dir + 2);
        } else if (tab[x][y] == 5) {
            cctv(x, y, dir);
            cctv(x, y, dir + 1);
            cctv(x, y, dir + 2);
            cctv(x, y, dir + 3);
        }

        // 다음 cctv
        dfs(idx + 1);

        // 복구
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tab[i][j] = backup[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
            if (tab[i][j] >= 1 && tab[i][j] <= 5) {
                v.push_back({i, j});
            }
        }
    }
    dfs(0);
    cout << res;

    return 0;
}