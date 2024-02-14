#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int map[11][11];
int answer = 987654321;
int paper[6];

bool possible(int r, int c, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (map[r + i][c + j] == 0) return false;
        }

    return true;
}

void dfs(int r, int c, int cnt) {
    while (map[r][c] == 0) {
        c++;
        if (c >= 10) {
            r++;
            if (r >= 10) {
                answer = min(answer, cnt);
                return;
            }
            c = 0;
        }
    }
    if (cnt >= answer) return;

    for (int i = 5; i >= 1; i--)  // 큰 종이부터
    {
        if (r + i > 10 || c + i > 10) continue;
        if (paper[i] >= 5) continue;

        if (possible(r, c, i)) {
            paper[i]++;
            for (int a = 0; a < i; a++)
                for (int b = 0; b < i; b++) {
                    map[r + a][c + b] = 0;
                }

            dfs(r, c, cnt + 1);

            paper[i]--;
            for (int a = 0; a < i; a++)
                for (int b = 0; b < i; b++) {
                    map[r + a][c + b] = 1;
                }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }

    dfs(0, 0, 0);
    if (answer == 987654321) answer = -1;

    cout << answer << endl;
    return 0;
}