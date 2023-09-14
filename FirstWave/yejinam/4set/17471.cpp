#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int population[11];
int graph[11][11];
int ret = 2147483647;
int check[11];
int check_bfs[11];

void bfs(int n, int sign)
{
    queue<int> queue;

    queue.push(n);
    while(queue.size() != 0)
    {
        int now = queue.front();
        queue.pop();

        for (int i = 0; graph[now][i] && i < N; i++)
        {
            if (check_bfs[graph[now][i]] == 0 && check[graph[now][i]] == sign)
            {
                queue.push(graph[now][i]);
                check_bfs[graph[now][i]] = 1;
            }
        }
    }
}

int is_pos()
{
	int A = 0;
    int B = 0;
	memset(check_bfs, 0, sizeof(check_bfs));
	for (int i = 1; i <= N; i++)
	{
		if (check_bfs[i] == 0 && check[i] == 1)
		{
			bfs(i, 1);
			A++;
		}
	}

    for (int i = 1; i <= N; i++)
    {
        if (check_bfs[i] == 0 && check[i] == 0)
        {
            bfs(i, 0);
            B++;
        }
    }
	if (A == 1 && B == 1)
		return 1;
	else
		return 0;
}

int cal()
{
    int a = 0;
    int b = 0;

    for (int i = 1; i <= N; i++)
    {
        if (check[i] == 1)
            a += population[i];
        else
            b += population[i];
    }
    return (abs(a - b));
}

void back_in_the_time(int now)
{
	if (now > N && is_pos())
	{
        ret = min(ret, cal());
		return ;
	}

	for (int i = now; i <= N; i++)
	{
		check[i] = 1;
		back_in_the_time(i + 1);
		check[i] = 0;
	}

}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> population[i];

	for (int i = 1; i <= N; i++)
	{
		int neighbor;
		cin >> neighbor;
		for (int j = 0; j < neighbor; j++)
			cin >> graph[i][j];
	}

	back_in_the_time(1);
    if (ret == 2147483647)
        ret = -1;
    cout << ret;
}
