#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cstring>

using namespace std;

int N, M, C;
int ret = 2147483647;
int map[51][51];
int check[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
std::vector<int> dir_x = {0, 1, 0, -1}; // 좌 하 우 상...?
std::vector<int> dir_y = {1, 0, -1, 0};


int in_range(int x, int y)
{
    if (x < 0 || N <= x)
        return (0);
    if (y < 0 || N <= y)
        return (0);
    return (1);
}

int bfs(int sx, int sy)
{
    int dis = 0;
    queue<vector<int>> queue;
    int check_map[51][51];

    memset(check_map, 0, sizeof(check_map));
    queue.push({sx, sy, 0});
    check_map[sx][sy] = 1;
    while (queue.size() != 0)
    {
        vector<int> top = queue.front();
        queue.pop();
        int x = top[0];
        int y = top[1];

        if (map[x][y] == 2)
        {
            dis = top[2];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int X = x + dir_x[i];
            int Y = y + dir_y[i];
            if (in_range(X, Y) && check_map[X][Y] == 0)
            {
                queue.push({X, Y, top[2] + 1});
                check_map[X][Y] = 1;
            }
        }
    }
    return (dis);
}

void get_distance()
{
    int total = 0;

    for (int i = 0; i < house.size(); i++)
    {   // 각 집에서 치킨집까지의 최단거리 구하기(bfs)
        int dis = 2147483647;
        for (int j = 0; j < chicken.size(); j++)
        {
            int tmp;
            if (map[chicken[j].first][chicken[j].second] == 2)
            {
                tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                if (tmp < dis)
                    dis = tmp;
            }
        }
        total += dis;
    }

    if (total < ret) //최솟값 갱신
        ret = total;
}

void back_in_the_chicken(int depth, int now)
{
    if (depth == M) // 치킨집 골랐으면 거리구하기
    {
        get_distance();
        return;
    }

    for (int i = now; i < C; i++) // 살릴 치킨집 구하기
    {
        if (check[i] == 1)
            continue;
        check[i] = 1;
        map[chicken[i].first][chicken[i].second] = 2;
        back_in_the_chicken(depth + 1, i + 1);
        map[chicken[i].first][chicken[i].second] = 0;
        check[i] = 0;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            if (num  == 1)
            {
                house.push_back({i, j});
                map[i][j] = 1;
            }
            if (num == 2)
                chicken.push_back({i, j});
        }
    }
    C = chicken.size();
    back_in_the_chicken(0, 0);
    cout  << ret;
}
