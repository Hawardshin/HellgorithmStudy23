#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct ITEM {
    ITEM() {}
    ITEM(int node, int dist_) : node(node), dist(dist_) {}

    bool operator<(const ITEM& other) const {
        return this->dist > other.dist;
    }
    int node, dist;
};

const int INF = 987654321;
int n, m, ans;
int src, dst;
int adj[500][500];
vector<int> dist, parent[500];

int dijkstra() {
    priority_queue<ITEM> pq;
    fill(dist.begin(), dist.end(), INF);

    pq.push(ITEM(src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        ITEM cur = pq.top();
        pq.pop();

        if (cur.dist > dist[cur.node])
            continue;

        for (int i = 0; i < n; ++i) {

            if (adj[cur.node][i] != 0 && dist[i] > dist[cur.node] + adj[cur.node][i]) {
                dist[i] = dist[cur.node] + adj[cur.node][i];
                parent[i].clear();
                parent[i].push_back(cur.node);
                pq.push(ITEM(i, dist[i]));
            }
            else if (adj[cur.node][i] != 0 && dist[i] == dist[cur.node] + adj[cur.node][i]) {
                parent[i].push_back(cur.node);
            }
        }
    }

    return dist[dst];
}

void remove_path() {
    queue<int> q;
    q.push(dst);
    bool visited[500] = { false, };
    visited[dst] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int p : parent[cur]) {

            adj[p][cur] = 0;

            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
            }
        }
    }

    return;
}

int main() {
    cin >> n >> m;

    while (!(n == 0 && m == 0)) {
        cin >> src >> dst;

        memset(adj, 0, sizeof(adj));
        dist.resize(n);

        for (int i = 0; i < n; ++i)
            parent[i].clear();

        for (int i = 0; i < m; ++i) {
            int from, to, weight;
            cin >> from >> to >> weight;
            adj[from][to] = weight;
        }

        ans = dijkstra();
        remove_path();
        ans = dijkstra();

        if (ans == INF)
            cout << "-1" << endl;
        else
            cout << ans << endl;

        cin >> n >> m;
    }

    return 0;
}
