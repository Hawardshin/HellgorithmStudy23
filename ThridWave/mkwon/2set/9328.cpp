#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef tuple<char, int, int> pos;

int t, n, m, vis[105][105];
char tab[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        memset(tab, 0, sizeof(tab));
        memset(vis, 0, sizeof(vis));
        int res = 0;
        queue<pair<int, int>> q;
        queue<pos> door;
        vector<char> key;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tab[i][j];
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (tab[i][j] == '.') {
                        q.push({i, j});
                        vis[i][j] = 1;
                    } else if (tab[i][j] == '$') {
                        q.push({i, j});
                        vis[i][j] = 1;
                        res++;
                    } else if (tab[i][j] >= 'A' && tab[i][j] <= 'Z') {
                        if (find(key.begin(), key.end(), tab[i][j] + 32) == key.end()) {
                            door.push({tab[i][j], i, j});
                            vis[i][j] = 1;
                        } else {
                            q.push({i, j});
                            vis[i][j] = 1;
                        }
                    } else if (tab[i][j] >= 'a' && tab[i][j] <= 'z') {
                        q.push({i, j});
                        int t = door.size();
                        while (t--) {
                            char alp;
                            int alpx, alpy;
                            tie(alp, alpx, alpy) = door.front();
                            door.pop();

                            if (alp == tab[i][j] - 32)
                                q.push({alpx, alpy});
                            else
                                door.push({alp, alpx, alpy});
                        }
                        vis[i][j] = 1;
                        key.push_back(tab[i][j]);
                    }
                }
            }
        }

        string str;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            key.push_back(str[i]);
            int t = door.size();
            while (t--) {
                char alp;
                int alpx, alpy;
                tie(alp, alpx, alpy) = door.front();
                door.pop();

                if (alp == str[i] - 32) {
                    q.push({alpx, alpy});
                    vis[alpx][alpy] = 1;
                } else
                    door.push({alp, alpx, alpy});
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
                    if (tab[nx][ny] == '.' && vis[nx][ny] == 0) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    } else if (tab[nx][ny] >= 'A' && tab[nx][ny] <= 'Z' && vis[nx][ny] == 0) {
                        if (find(key.begin(), key.end(), tab[nx][ny] + 32) == key.end()) {
                            door.push({tab[nx][ny], nx, ny});
                            vis[nx][ny] = 1;
                        } else {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    } else if (tab[nx][ny] >= 'a' && tab[nx][ny] <= 'z' && vis[nx][ny] == 0) {
                        q.push({nx, ny});
                        int t = door.size();
                        while (t--) {
                            char alp;
                            int alpx, alpy;
                            tie(alp, alpx, alpy) = door.front();
                            door.pop();

                            if (alp == tab[nx][ny] - 32)
                                q.push({alpx, alpy});
                            else
                                door.push({alp, alpx, alpy});
                        }
                        vis[nx][ny] = 1;
                        key.push_back(tab[nx][ny]);
                    } else if (tab[nx][ny] == '$' && vis[nx][ny] == 0) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        res++;
                    }
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}
