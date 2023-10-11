#include <iostream>
#include <vector>

using namespace std;

int N, M, X;
int check[100000];
vector<pair<int, int>> graph[100000];

void dfs(int now, int up, int &ret)
{
    if (check[now])
        return;
    ret++;
    check[now] = 1;
    for(int i = 0; i < graph[now].size(); i++)
    {
        if (graph[now][i].second == up)
            dfs(graph[now][i].first, up, ret);
    }
}

int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, -1});
    }

    int up = 0, down = 0;
    dfs(X, -1, up);
    check[X] = 0;
    dfs(X, 1, down);
    cout << "ret: " << up << " " << N + 1 - down;
}
