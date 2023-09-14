#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> > &graph, std::vector<int> &check, int now, int n)
{
	check[now] = 1; // 방문 표시
	for (int i = 0; i < n; i++)
	{
		if (graph[now][i] == 1 && check[i] == 0) // 연결이 되어있고 아직 방문하지않았다면
			dfs(graph, check, i, n); //방문
	}
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	std::vector<std::vector<int> > graph(n, std::vector<int>(n, 0)); //인접행렬쓰기
	std::vector<int> check(n, 0);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}
	int ret = 0;
	for(int i = 0; i < n; i++)
	{
		if (check[i] == 0) // 방문이 안되어있다면
		{
			dfs(graph, check, i, n); // 탐색
			ret++;
		}
	}
	std::cout << ret;
}
