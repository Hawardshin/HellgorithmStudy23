#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, h, ladder_cnt;
bool ladder_pos[31][11], flag = false;

void dfs(int y, int cnt) {
    if (ladder_cnt == cnt) {
        bool possible = true;
        for (int i = 1; i <= n; i++) {  // 세로선
            int verti = i;
            for (int j = 0; j < h; j++) {  // 가로선
                int hight = j;

                if (ladder_pos[hight][verti]) {
                    // 오른쪽으로 가는 경우
                    verti++;
                } else if (verti > 1 && ladder_pos[hight][verti - 1]) {
                    // 왼쪽으로 가는 경우
                    verti--;
                }
            }
            if (verti != i) {  // 잘못된 세로선
                possible = false;
                break;
            }
        }
        if (possible) flag = true;
        return;
    }

    // 가로선 추가하는 코드
    for (int i = y; i < h; i++) {
        for (int j = 1; j < n; j++) {
            if (!ladder_pos[i][j - 1] && !ladder_pos[i][j] && !ladder_pos[i][j + 1]) {
                // 사다리가 추가 될 수 있는 위치인지 확인
                ladder_pos[i][j] = true;   // 사다리 추가
                dfs(i, cnt + 1);           // y좌표와 사다리 추가 개수 카운트
                ladder_pos[i][j] = false;  // 추가한 사다리 삭제
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder_pos[a - 1][b] = true;
    }

    for (int i = 0; i <= 3; i++) {
        ladder_cnt = i;
        dfs(0, 0);
        if (flag) {
            cout << ladder_cnt << endl;
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}