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

void bfs(int n, int sign) // 구역번호를받아서 
{
    queue<int> queue;

    queue.push(n);
    while(queue.size() != 0)
    {
        int now = queue.front();
        queue.pop();

        for (int i = 0; graph[now][i] && i < N; i++)
        {
            if (check_bfs[graph[now][i]] == 0 && check[graph[now][i]] == sign) // 이웃구역이 같은구역인지 보고 큐에 집어넣기
            {
                queue.push(graph[now][i]);
                check_bfs[graph[now][i]] = 1;
            }
        }
    }
}

int is_pos() // 두구역이 가능한지 체크 
{
	int A = 0;
    int B = 0;
	memset(check_bfs, 0, sizeof(check_bfs));
	for (int i = 1; i <= N; i++)
	{
		if (check_bfs[i] == 0 && check[i] == 1) // 1구역애들 bfs돌리기
		{
			bfs(i, 1);
			A++;
		}
	}

    for (int i = 1; i <= N; i++)
    {
        if (check_bfs[i] == 0 && check[i] == 0) // 0구역애들 bfs돌리기
        {
            bfs(i, 0);
            B++;
        }
    }
	if (A == 1 && B == 1) // 둘다 카운트가 1번씩 이면 1반환
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
        if (check[i] == 1) // 체크배열에 1로기록 되어잇으면 a인구수에 기록 
            a += population[i];
        else
            b += population[i]; // 0이면 b인구수에 기록
    }
    return (abs(a - b)); // 차이 반환 
}

void back_in_the_time(int now)
{
	if (now > N && is_pos()) // now가 N이 됐다면 탐색끝
	{
        ret = min(ret, cal()); // 계산후 갱신
		return ;
	}

	for (int i = now; i <= N; i++)
	{
		check[i] = 1; // 체크에 기록 (구역을 1팀, 0팀으로 나눌것)
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
			cin >> graph[i][j]; // 이웃간선 2차원배열 그래프에 기록
	}

	back_in_the_time(1);
    if (ret == 2147483647)
        ret = -1;
    cout << ret;
}
