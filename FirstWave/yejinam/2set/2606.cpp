#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> > &graph, std::vector<int> &check, int now, int n)
{
	check[now] = 1; // 방문 표시
	for (int i = 0; i < n; i++)
	{
		if (graph[now][i] == 1 && check[i] == 0) // 연결되어있고 방문하지않았다면 dfs~
			dfs(graph, check, i, n);
	}
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	std::vector<std::vector<int> > graph(n, std::vector<int>(n, 0));
	std::vector<int> check(n, 0);

	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}

	int ret = 0;
	dfs(graph, check, 0, n); // 1번 컴퓨터 dfs

	for (int i = 1; i < n; i++) // 감염된(방문된) 컴퓨터 수 세기
		if (check[i] == 1)
			ret++;
	std::cout << ret;
}
