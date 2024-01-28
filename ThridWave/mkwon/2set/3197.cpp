#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, temp = 0, vis[1505][1505];
char tab[1505][1505];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue<pair<int, int>> bjo, nextbjo, water, melt;

int goBjo() {
    while (!bjo.empty()) {
        int x = bjo.front().first;
        int y = bjo.front().second;
        bjo.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
                if (vis[nx][ny] == 1) continue;

                if (tab[nx][ny] == '.')
                    bjo.push({nx, ny});
                else if (tab[nx][ny] == 'X')
                    nextbjo.push({nx, ny});
                else if (tab[nx][ny] == 'L')
                    return 1;
                vis[nx][ny] = 1;
            }
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
            if (tab[i][j] == 'L') {
                if (!temp) {
                    nextbjo.push({i, j});
                    temp = 1;
                    vis[i][j] = 1;
                }
                water.push({i, j});
            } else if (tab[i][j] == '.')
                water.push({i, j});
        }
    }

    int res = 1;
    while (1) {
        int t = water.size();
        while (t--) {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
                    if (tab[nx][ny] == 'X') {
                        melt.push({nx, ny});
                        tab[nx][ny] = '.';
                    }
                }
            }
        }

        bjo = nextbjo;
        while (!nextbjo.empty()) nextbjo.pop();
        if (goBjo()) break;

        water = melt;
        while (!melt.empty()) melt.pop();

        res++;
    }
    cout << res;

    return 0;
}