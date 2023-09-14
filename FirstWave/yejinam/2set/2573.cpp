#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int Map[400][400];
bool visited[400][400];
int mnum = 0;

vector <pair<int, int>> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void melting() {
	int x, y, nx, ny;
	int tmp[400][400];

	for (int i = 0; i < v.size(); i++) {
		x = v[i].first;
		y = v[i].second;
		if (Map[x][y] == 0) continue;

		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			nx = x + dx[j];
			ny = y + dy[j];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (Map[nx][ny] == 0)cnt++;
		}

		if (Map[x][y] - cnt <= 0) {
			mnum--;
			tmp[x][y] = 0;
		}
		else tmp[x][y] = Map[x][y] - cnt;
	}

	for (int i = 0; i < v.size(); i++) {
		if (Map[v[i].first][v[i].second] == 0) continue;
		Map[v[i].first][v[i].second] = tmp[v[i].first][v[i].second];
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
		if (Map[nx][ny] > 0) {
			dfs(nx,ny); 
            // 모든 길을 확인해야 하므로 방문->false 해줄 필요 없다.
		}
	}
}

bool chuck() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && Map[i][j] > 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt >= 2) return true;
	else return false;
}

void Solve() {
	int year = 0;
	while (1) {
		year++;
		melting();
		if (mnum == 0) {
			cout << 0 << endl;
			return;
		}
		memset(visited, false, sizeof(visited));//visited 초기화
		if (chuck()) {
			cout << year << endl;
			return;
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != 0) {
				v.push_back({ i,j });
				mnum++;
			}
		}

	Solve();

	return 0;


}
