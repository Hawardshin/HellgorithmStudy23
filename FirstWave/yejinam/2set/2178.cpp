#include <iostream>
#include <vector>
#include <queue>

std::vector<int> dir_x = {0, 1, 0, -1}; // 좌 하 우 상...?
std::vector<int> dir_y = {1, 0, -1, 0};

int in_range(int x, int y, int n, int m)
{
	if (x < 0 || n <= x)
		return (0);
	if (y < 0 || m <= y)
		return (0);
	return (1);
}

int bfs(std::vector<std::string> &map, int n, int m)
{
	int ret = n * m;
	std::queue<std::vector<int> > queue;
	std::vector<std::vector<int> > check(n, std::vector<int>(m, 0));

	queue.push({0, 0, 1}); // 시작값 세팅
	while (queue.size() != 0)
	{
		std::vector<int> top = queue.front(); // 탐색할 위치 꺼내고
		int x = top[0];
		int y = top[1];
		if (x == n - 1 && y == m - 1)
			ret = top[2];
		queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int X = x + dir_x[i];
			int Y = y + dir_y[i];
			if (in_range(X, Y, n, m) == 1 && map[X][Y] == '1' && check[X][Y] == 0)
			{ // 아직 방문안한 주변 경로 차례대로 푸쉬
				queue.push({X, Y, top[2] + 1});
				check[X][Y] = 1; // 방문표시
			}
		}
	}
	return ret;
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	std::vector<std::string> map;

	for(int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		map.push_back(str);
	}

	int ret = bfs(map, n, m);

	std::cout << ret;
}
