#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int check[101][101];
int n;
int answer = 987654321;

int pos_x[4] = { 0,1,0,-1 };
int pos_y[4] = { 1,0,-1,0 };

void dfs(int x, int y, int index)
{
	map[x][y] = index;

	for (int i = 0; i < 4; i++)
	{
		int X = x + pos_x[i];
		int Y = y + pos_y[i];
		if ((0 <= X && X < n && 0 <= Y && Y < n) 
            && map[X][Y] == -1)
			dfs(X, Y, index);
	}
}

void bfs(int index)
{
	queue<pair<int, int> > queue;
    
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == index)
			{
				queue.push({i, j});
				check[i][j] = 1;
			}
		}
    }

	int result = 0;

	while (!queue.empty())
	{
		int a = queue.size();
		for (int i = 0; i < a; i++)
		{
			int x = queue.front().first;
			int y = queue.front().second;
			queue.pop();

			for (int i = 0; i < 4; i++)
			{
				int X = x + pos_x[i];
				int Y = y + pos_y[i];
				if ((0 <= X && X < n && 0 <= Y && Y < n) && map[X][Y] != 0 && map[X][Y] != index) 
				{
					answer = min(answer, result);
					return;
				}
				if ((0 <= X && X < n && 0 <= Y && Y < n)  && map[X][Y] == 0 && check[X][Y] == 0)
				{
					check[X][Y] = 1;
					queue.push({X, Y});
				}

			}
		}
		result++;
	}
}

int main()
{
	cin >> n;
	
    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
    }
	
    int index = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == -1)
			{
				dfs(i, j, index);
				index++;
			}
		}

	for (int i = 1; i < index; i++)
	{
		memset(check, 0, sizeof(check));
		bfs(i);
	}

	cout << answer << endl;
	return 0;
}
