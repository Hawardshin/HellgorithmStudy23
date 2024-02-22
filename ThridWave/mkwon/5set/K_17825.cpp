#include <algorithm>
#include <iostream>

using namespace std;

int map[][24] = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
                 {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40},  // 12
                 {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40},
                 {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40}};
int loc[4], road[4], dice[10], ans, End[4] = {21, 13, 17, 23};

bool canMove(int cur) {
    int n = map[road[cur]][loc[cur]];
    if (!n) return true;
    for (int i = 0; i < 4; ++i) {
        if (i == cur) continue;
        if (map[road[i]][loc[i]] != n) continue;
        if (n == 16 || n == 22 || n == 24 || n == 26 || n == 28) {
            if ((loc[i] == loc[cur]) && (road[i] == road[cur])) return false;
        } else if (n == 30) {
            if (road[cur] == 0 && loc[cur] == 15) {
                if (loc[i] == 15) return false;
            } else if (road[cur] == 3 && loc[cur] == 15) {
                if (road[i] == 3 && loc[i] == 15) return false;
            } else {
                if (road[i] == 3 && loc[i] == 15) continue;
                return false;
            }
        } else
            return false;
    }
    return true;
}

void func(int dep, int score) {
    if (dep >= 10) {
        ans = max(ans, score);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (loc[i] > 0 && !map[road[i]][loc[i]]) continue;
        if (i > dep) continue;
        int pl = loc[i], pr = road[i];
        loc[i] += dice[dep];
        if (loc[i] > End[road[i]]) loc[i] = End[road[i]];
        int next = map[road[i]][loc[i]];
        if (canMove(i)) {
            if (next == 10 || next == 20 || (road[i] == 0 && next == 30)) road[i] = next / 10;
            func(dep + 1, score + next);
        }
        loc[i] = pl;
        road[i] = pr;
    }
}

int main() {
    for (int i = 0; i < 10; ++i) cin >> dice[i];
    func(0, 0);
    cout << ans;
    return 0;
}
