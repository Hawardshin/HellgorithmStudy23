#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m, s, e;

int earn[50];
bool check[50];
vector<long long> dist(50, 2147483647);
vector<pair<int, int> > map[50];
queue<int> cycle;

bool BFS()
{
    while (!cycle.empty()) {
        int cur = cycle.front();
        cycle.pop();

        for (auto now : map[cur]) {
            int next = now.first;
            if (check[next] == 0)
            {
                check[next] = true;
                cycle.push(next);
            }
        }
    }

    if (check[e])
        return true;
    return false;
}

int main()
{
    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        map[u].push_back({v, w});
    }

    for (int i = 0; i < n; ++i)
        cin >> earn[i];
    

    dist[s] = -earn[s];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto cur : map[j]) {
                int next = cur.first;
                long long nextCost = cur.second;

                if (dist[j] != 2147483647 && dist[next] > dist[j] + nextCost - earn[next]) 
                {
                    dist[next] = dist[j] + nextCost - earn[next];
                    if (i == n) { 
                        check[j] = true;
                        cycle.push(j);
                    }
                }
            }
        }
    }
    
    if (dist[e] == 2147483647) 
        cout << "gg" << endl; 
    else {
        if (BFS()) 
            cout << "Gee" << endl; 
        else 
            cout << -dist[e] << endl;
    }
    return 0;
}
