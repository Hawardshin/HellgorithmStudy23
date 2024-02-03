#include <algorithm>
#include <iostream>

using namespace std;

int n, m, alpha[30], res = 0;
char tab[25][25];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!alpha[tab[nx][ny] - 'A']) {
                alpha[tab[nx][ny] - 'A'] = 1;
                dfs(nx, ny, cnt + 1);
                alpha[tab[nx][ny] - 'A'] = 0;
            }
        }
    }
    if (cnt > res) res = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tab[i][j];
        }
    }

    alpha[tab[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << res;

    return 0;
}