#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b;
int pedigree[101][101];
int check[101];

int bfs(int start, int end)
{
    queue<pair<int, int> > q;
    q.push({start, 0});

    while(!q.empty())
    {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (now == end)
            return depth;
        check[now] = 1;
        for(int i = 1; i <= n; i++)
        {
            if (pedigree[now][i] == 1 && check[i] == 0)
                q.push({i, depth+1});
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        pedigree[x][y] = 1;
        pedigree[y][x] = 1;
    }

    cout << bfs(a, b);
}
