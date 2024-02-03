#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147483647

int n, res = INF;
int tab[12][12] = {
    0,
};
int vis[12][12] = {
    0,
};

void dfs(int x, int y, int flower, int cost) {
    // 가격 계산
    if (flower == 3) {
        if (cost < res) res = cost;
        return;
    }

    // 화단
    for (int i = x; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            // 테두리 제외 심기 가능
            if (i > 1 && j > 1 && i < n && j < n) {
                // 진짜 심기 가능
                if (vis[i][j] == 0 && vis[i - 1][j] == 0 && vis[i + 1][j] == 0 && vis[i][j - 1] == 0 && vis[i][j + 1] == 0) {
                    vis[i][j] = 1;
                    vis[i - 1][j] = 1;
                    vis[i + 1][j] = 1;
                    vis[i][j - 1] = 1;
                    vis[i][j + 1] = 1;

                    int temp = 0;
                    temp += tab[i][j];
                    temp += tab[i - 1][j];
                    temp += tab[i + 1][j];
                    temp += tab[i][j - 1];
                    temp += tab[i][j + 1];

                    dfs(i, j, flower + 1, cost + temp);

                    vis[i][j] = 0;
                    vis[i - 1][j] = 0;
                    vis[i + 1][j] = 0;
                    vis[i][j - 1] = 0;
                    vis[i][j + 1] = 0;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tab[i][j];
        }
    }

    dfs(1, 1, 0, 0);

    cout << res;

    return 0;
}