#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
 
vector<pair<int, int> >graph[505];
int dis[505];
vector<int>way[505];
int check[505];
 
void dijkstra(int x) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queue;
    
    queue.push(make_pair(0, x));
    dis[x] = 0;
    
    while (!queue.empty()) {
        int now = queue.top().second;
        int w= queue.top().first;
        queue.pop();

        if (dis[now] < w) 
            continue;
        for (int i = 0; i < graph[now].size(); i++) {
            if (graph[now][i].second == -1) // 제외된 간선 넘어감
                continue;
            int next = graph[now][i].first;
            int W = graph[now][i].second;

            if (dis[now] + W < dis[next]) 
            {
                dis[next] = dis[now] + W;
                way[next].clear(); 
                way[next].push_back(now); //갱신
                queue.push(make_pair(dis[next], next));
            }
            else if (dis[now] + W == dis[next])
                way[next].push_back(now);
            else 
                continue;
        }
    }
}
 
void bfs(int x) {
    queue<int>q;
    q.push(x);

    while (!q.empty()) 
    {
        x = q.front();
        q.pop();

        for (int i = 0; i < way[x].size(); i++) 
        {
            int X = way[x][i];
            for (int j = 0; j < graph[X].size(); j++) 
            {
                if (graph[X][j].first == x) 
                    graph[X][j].second = -1; // 간선 삭제
            }
            if (check[X] != 1)
            {
                check[X] = 1;
                q.push(X);
            }
        }
    }
}
 
int main() {
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int n, m, start, end, u, v, e;
       
        memset(graph, 0, sizeof(graph));
        memset(way, 0, sizeof(way));
        memset(check, 0, sizeof(check));
        memset(dis, 127, sizeof(dis));
        cin >> n >> m;
        if (n == 0 && m == 0) 
            break;
        
        cin >> start >> end;
        for (int i = 0; i < m; i++) 
        {
            cin >> u >> v >> e;
            graph[u].push_back({v, e});
        }

        int INF = dis[0];

        dijkstra(start); // 정점까지의 최단 거리 구함
        bfs(end); // end 에서 start까지의 간선 제거
        memset(dis, 127, sizeof(dis)); 
        dijkstra(start); //간선 제거후 최단 거리 구함
        
        if (dis[end] == INF) 
            cout << -1 << "\n";
        else 
            cout << dis[end] << "\n";
    }
}
