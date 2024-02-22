#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int N, x, y, d, g, cnt;
int map[MAX][MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
vector<int> direction;

void Make_Dragon_Curve() {
    int size = direction.size();
    for (int i = size - 1; i >= 0; i--) {
        int temp = (direction.at(i) + 1) % 4;
        x += dx[temp];
        y += dy[temp];
        map[x][y] = 1;
        direction.push_back(temp);
    }
}

void Count_Square() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            // 사각형의 네 꼭지점이 모두 드래곤 커브 상에 존재하는지 확인 후 카운트 증가
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] && map[i + 1][j] == 1) cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--) {
        direction.clear();
        cin >> x >> y >> d >> g;

        map[x][y] = 1;

        // 0세대
        x += dx[d];
        y += dy[d];
        map[x][y] = 1;
        direction.push_back(d);

        // ~ g세대
        while (g--) {
            Make_Dragon_Curve();
        }
    }

    Count_Square();
    cout << cnt << endl;
}
