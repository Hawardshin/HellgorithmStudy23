#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define INF 987654321

int n, m, s, e;

int earn[50];
bool visited[50] = {false, };
vector<long long> dist(50, INF);
vector<pair<int, int> > map[50];
queue<int> cycleNode;

bool BFS() 
{
    while (!cycleNode.empty()) {
        int cur = cycleNode.front(); cycleNode.pop();

        for (auto x : map[cur]) {
            int next = x.first;
            if (visited[next]) continue;
            visited[next] = true;
            cycleNode.push(next);
        }
    }
    if (visited[e]) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ios_base::sync_with_stdio(false);
    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back({v, w});
    }
    for (int i = 0; i < n; ++i) {
        cin >> earn[i];
    }

    dist[s] = -earn[s];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) { 
            for (auto cur : map[j]) { 
                int next = cur.first;
                long long nextCost = cur.second;
                if (dist[j] != INF && dist[next] > dist[j] + nextCost - earn[next]) {
                    dist[next] = dist[j] + nextCost - earn[next];
                    if (i == n) { 
                        visited[j] = true; cycleNode.push(j); 
                    }
                }
            }
        }
    }

	if (dist[e] == INF) cout << "gg" << endl; 
    else {
        if (BFS()) cout << "Gee" << endl;
        else cout << -dist[e] << endl;
    }

	return 0;
}
