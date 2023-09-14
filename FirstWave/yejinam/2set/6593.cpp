#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int dir_x[6] = {0, 1, 0, -1, 0, 0}; // 좌 하 우 상...?
int dir_y[6] = {1, 0, -1, 0, 0, 0};
int dir_f[6] = {0, 0, 0, 0, 1, -1};
bool check[31][31][31];
int in_range(int x, int y, int f, int l, int r, int c)
{
	if (f < 0 || l <= f)
		return (0);
	if (x < 0 || r <= x)
		return (0);
	if (y < 0 || c <= y)
		return (0);
	return (1);
}

int bfs(int l, int r, int c, int map[31][31][31], std::vector<int> s)
{
	int ret = 0;
	std::queue<std::vector<int> > queue;

	queue.push(s); // 시작값 세팅
	check[s[0]][s[1]][s[2]] = 1; // 방문표시
	while (queue.size() != 0)
	{
		std::vector<int> top = queue.front(); // 탐색할 위치 꺼내고
		int f = top[0];
		int x = top[1];
		int y = top[2];
		if (map[f][x][y] == 'E')
			ret = top[3];
		queue.pop();
		for (int i = 0; i < 6; i++)
		{
			int X = x + dir_x[i];
			int Y = y + dir_y[i];
			int F = f + dir_f[i];
			if (in_range(X, Y, F, l, r, c) == 1 && map[F][X][Y] != '#' && check[F][X][Y] == false)
			{ // 아직 방문안한 주변 경로 차례대로 푸쉬
				queue.push({F, X, Y, top[3] + 1});
				check[F][X][Y] = true; // 방문표시
			}
		}
	}
	return ret;
}

int main()
{

	while (true)
	{
		int l, r, c;
		std::vector<int> s;
		std::cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		int map[31][31][31];
        memset(check, 0,sizeof(check));
		memset(map,0, sizeof(map));
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				std::string str;
				std::cin >> str;
				for (int k = 0; k < c; k++)
				{
					map[i][j][k] = str[k];
					if (map[i][j][k] == 'S')
						s = {i, j, k, 0};
				}
			}
		}

		int ret = bfs(l, r, c, map, s);

		if (ret)
			std::cout << "Escaped in " << ret << " minute(s)." << std::endl;
		else
			std::cout << "Trapped!" <<  std::endl;
	}
	return (0);
}
