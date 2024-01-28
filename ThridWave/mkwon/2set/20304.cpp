#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n;
int max_bit_size = 0;  // 비밀번호 최댓값의 비트 자리값 저장
int m;
vector<int> p;

queue<int> q;
vector<int> discovered(1000001, 0);
vector<int> depth(1000001, 0);

// 최댓값의 비트 자리값을 계산하는 함수
void Make_max_bit_size() {
    int check = n;

    while (1) {
        if (check / 2 != 0) {
            max_bit_size++;
            check /= 2;
        }

        else {
            max_bit_size++;
            break;
        }
    }
}

// 주어진 비밀번호들로부터 최장 경로를 찾는 함수
int Solve() {
    // 주어진 비밀번호들을 큐에 추가하고 방문 여부를 표시함
    for (int i = 0; i < p.size(); i++) {
        q.push(p[i]);
        discovered[p[i]] = 1;
        depth[p[i]] = 0;
    }

    // BFS를 통해 최장 경로 계산
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        // 비트를 하나씩 바꿔가며 이동 가능한 상태를 확인함
        for (int i = 0; i < max_bit_size; i++) {
            int there = (here ^ (1 << i));

            // 이동 가능하면 큐에 추가하고 방문 여부 및 깊이를 업데이트함
            if (there <= n && discovered[there] == 0) {
                discovered[there] = 1;
                depth[there] = depth[here] + 1;
                q.push(there);
            }
        }
    }

    // 최장 경로 중 가장 긴 값 반환
    int ret = -1;
    for (int i = 0; i <= n; i++) ret = max(ret, depth[i]);

    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 입력 받기
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int pi;
        cin >> pi;

        p.push_back(pi);
    }

    // 최댓값의 비트 자리값 계산
    Make_max_bit_size();

    // 최장 경로 출력
    cout << Solve();

    return 0;
}
