#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int graph[100001];
bool check[100001];
bool done[100001];
int cnt;

void dfs(int n) {

	check[n] = true;
	int next = graph[n];

	
	if (!check[next]) {
		dfs( next);
	}
	else if (!done[next]) {
		for (int i = next; i != n; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}
	done[n] = true;
}


int main() {

    int t, n;
    
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
			}
		}
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));
        
		cout << n - cnt << '\n';
		cnt = 0;
	}


	return 0;
}
