#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m, start, to;
vector<pair<int, int> > bus[1001];
int dist[1001];

void bfs()
{
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -(pq.top().first);

		pq.pop();
		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < bus[cur].size(); i++)
		{
			int next = bus[cur][i].first;
			int ncost = cost + bus[cur][i].second;

			if (dist[next] > ncost)
			{
				dist[next] = ncost;
				pq.push(make_pair(-ncost, next));
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, d, c;

		cin >> s >> d >>c;
		bus[s].push_back(make_pair(d, c));
	}

	cin >> start >> to;

	fill(dist, dist + 1001, 987654321);

	bfs();
	cout << dist[to]<<endl;
}