#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T, N, M, A, B;
int visited[1004];

int dfs(int pos, vector<int> vec[1004], int depth) {
    if (visited[pos]) return 0;
    visited[pos] = 1;
    for (int i = 0; i < vec[pos].size(); ++i) {
        int n = vec[pos][i];
        if (!visited[n]) depth += dfs(n, vec, 1);
    }
    return depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        vector<int> v[1004];
        memset(visited, 0, sizeof(visited));
        int root = 0, depth = 0;
        cin >> N >> M;

        for (int i = 1; i <= M; i++) {
            cin >> A >> B;
            v[A].push_back(B);
            v[B].push_back(A);
            if (!root) root = A;
        }

        if (M != N - 1) {
            cout << "graph\n";
            continue;
        }
        if (dfs(root, v, 1) == N)
            cout << "tree\n";
        else
            cout << "graph\n";
    }
}