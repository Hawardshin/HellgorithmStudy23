#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50];
int check[50][50];
int pos_x[4] = {0, -1, 0, 1};
int pos_y[4] = {-1, 0, 1, 0};
int pos_w[4] = {1, 2, 4, 8};

int cnt = 0;
int biggest = 0;
int bigger = 0;

int in_range(int x, int y)
{
    if (x < 0 || M <= x)
        return 0;
    if (y < 0 || N <= y)
        return 0;
    return 1;
}

int bfs(int start_x, int start_y)
{
    queue<pair<int, int>> queue;
    int size = 0;

    queue.push ({start_x, start_y});
    check[start_x][start_y] = 1;
    while (queue.size() != 0)
    {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        size++;
        for (int i = 0; i < 4; i++)
        {
            int X = x + pos_x[i];
            int Y = y + pos_y[i];
            int wall = pos_w[i];
            if (in_range(X, Y) && ( (map[x][y] & wall) != wall)
                    && check[X][Y] == 0)
            {
                check[X][Y] = 1;
                queue.push({X, Y});
            }
        }
    }
    return size;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];      

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j] == 0)
            {
                biggest = max(bfs(i, j), biggest);
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int X = i + pos_x[k];
                int Y = j + pos_y[k];
                int wall = pos_w[k];
                if (in_range(X, Y) &&  ((map[i][j] & wall) == wall)) 
                {
                    map[i][j] -= wall;
                    memset(check, 0, sizeof(check));
                    bigger = max(bfs(i, j), bigger);
                    map[i][j] += wall;
                }

            }
        }
    }
    cout << cnt << endl;
    cout << biggest << endl;
    cout << bigger << endl;
}
