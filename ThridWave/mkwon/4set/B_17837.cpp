#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<vector<vector<int>>> nodeMap;
int N, K;
struct position {
    int y, x;
    const position operator+(const position &other) const { return {y + other.y, x + other.x}; }
    const bool isOut() const { return y < 0 || x < 0 || y >= N || x >= N || map[y][x] == 2; }
} dir[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node {
    position pos;
    int dir;
    void changeDir() {
        switch (dir) {
            case 0:
                dir = 1;
                break;
            case 1:
                dir = 0;
                break;
            case 2:
                dir = 3;
                break;
            case 3:
                dir = 2;
                break;
        }
    }
};
vector<node> nodes;
void input() {
    cin >> N >> K;
    map = vector<vector<int>>(N, vector<int>(N));
    nodeMap = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>()));
    nodes = vector<node>(K);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        cin >> nodes[i].pos.y >> nodes[i].pos.x >> nodes[i].dir;
        --nodes[i].pos.y, --nodes[i].pos.x, --nodes[i].dir;
        nodeMap[nodes[i].pos.y][nodes[i].pos.x].push_back(i);
    }
}
bool move() {
    for (int i = 0; i < K; ++i) {
        node &n = nodes[i];
        position nextPos = n.pos + dir[n.dir];

        if (nextPos.isOut()) {
            n.changeDir();
            nextPos = n.pos + dir[n.dir];

            if (nextPos.isOut()) {
                continue;
            }
        }

        vector<int> &group = nodeMap[n.pos.y][n.pos.x];

        auto iter = find(group.begin(), group.end(), i);
        vector<int> myGroup = vector<int>(iter, nodeMap[n.pos.y][n.pos.x].end());
        group.erase(iter, group.end());

        if (map[nextPos.y][nextPos.x] == 1) {
            reverse(myGroup.begin(), myGroup.end());
        }

        for (int j : myGroup) {
            nodes[j].pos = nextPos;
            nodeMap[nextPos.y][nextPos.x].push_back(j);
        }

        if (nodeMap[nextPos.y][nextPos.x].size() >= 4) {
            return true;
        }
    }
    return false;
}
int main() {
    input();
    for (int i = 1; i <= 1000; ++i) {
        if (move()) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
