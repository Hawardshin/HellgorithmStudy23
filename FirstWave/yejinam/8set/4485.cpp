#include <iostream>
#include <queue>
using namespace std;

int N, pb;
int map[125][125];
int check[125][125];
int pos_x[4] = {0, 1, 0, -1};
int pos_y[4] = {1, 0 ,-1, 0};

int bfs(int N)
{
    queue<pair<int, int> > queue;
    
    queue.push({0, 0});
    check[0][0] = map[0][0];

    while (!queue.empty())
    {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = x + pos_x[i];
            int Y = y + pos_y[i];
            if (X >= 0 && X < N && Y >= 0 && Y < N)
                if (check[X][Y] > check[x][y] + map[X][Y])
                {
                    check[X][Y] = check[x][y] + map[X][Y];
                    queue.push({X, Y});
                }
        }
    }

}

int main()
{
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                check[i][j] = 2147483647;
            }
        }
        bfs(N);
        cout << "Problem " << ++pb <<": " << check[N - 1][N - 1] << endl;
    }
}
