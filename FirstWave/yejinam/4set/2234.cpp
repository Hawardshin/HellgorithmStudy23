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
        size++; // 방크기 더하기
        for (int i = 0; i < 4; i++)
        {
            int X = x + pos_x[i]; // 동서남북
            int Y = y + pos_y[i];
            int wall = pos_w[i]; // 벽 비트연산할 값
            if (in_range(X, Y) && ( (map[x][y] & wall) != wall) // 벽이 없으면
                    && check[X][Y] == 0)
            {
                check[X][Y] = 1; // 방문체크
                queue.push({X, Y}); //큐 넣기
            }
        }
    }
    return size; // 방크기 리턴
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
                biggest = max(bfs(i, j), biggest); // bfs돌면서 최대방크기 갱신 
                cnt++; // 방갯수 카운트
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
                if (in_range(X, Y) &&  ((map[i][j] & wall) == wall)) // 벽이있으면 
                {
                    map[i][j] -= wall; // 부수고 
                    memset(check, 0, sizeof(check));
                    bigger = max(bfs(i, j), bigger); // bfs후 갱신
                    map[i][j] += wall;
                }

            }
        }
    }
    cout << cnt << endl;
    cout << biggest << endl;
    cout << bigger << endl;
}
