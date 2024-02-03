#include <cstring>
#include <iostream>
#define INF 2147483647

using namespace std;

int n, scv[5], vis[5];
int dp[61][61][61];

int dfs(int x, int y, int z) {
    if (x == 0 && y == 0 && z == 0)
        return 0;
    else if (x < 0)
        return dfs(0, y, z);
    else if (y < 0)
        return dfs(x, 0, z);
    else if (z < 0)
        return dfs(x, y, 0);

    int& res = dp[x][y][z];
    if (res != -1) return res;
    res = INF;

    res = min(res, dfs(x - 9, y - 3, z - 1) + 1);
    res = min(res, dfs(x - 9, y - 1, z - 3) + 1);
    res = min(res, dfs(x - 3, y - 9, z - 1) + 1);
    res = min(res, dfs(x - 3, y - 1, z - 9) + 1);
    res = min(res, dfs(x - 1, y - 9, z - 3) + 1);
    res = min(res, dfs(x - 1, y - 3, z - 9) + 1);

    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> scv[i];
    memset(dp, -1, sizeof(dp));

    cout << dfs(scv[0], scv[1], scv[2]);

    return 0;
}
