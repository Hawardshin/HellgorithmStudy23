#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M, T, D;
int res;
int p[26][26]; // 지도 정보
int check[26][26]; // 등산 시간
int back[26][26]; // 하산 시간
int pos_x[4] = { -1,0,0,1 };
int pos_y[4] = { 0,-1,1,0 };

void bfs()
{
	memset(check, -1, sizeof(check));
	queue<pair<int, int>> q;
	
    q.push({1, 1});
	check[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = x + pos_x[i];
			int Y = y + pos_y[i];
			if (X < 1 || Y < 1 || X > N || Y > M)
                continue;
			if (abs(p[X][Y] - p[x][y]) > T)
                continue; //높이차가 T보다 크면 불가능
			if (p[X][Y] <= p[x][y]) {
				if (check[x][y] + 1 <= D
                        && (check[X][Y] == -1 || check[X][Y] > check[x][y] + 1)) {
					check[X][Y] = check[x][y] + 1;
					q.push({ X,Y });
				}
			}
			else {
				int nextTime = (p[X][Y] - p[x][y]) * (p[X][Y] - p[x][y]);
				if (check[x][y] + nextTime <= D
                        && (check[X][Y] == -1 || check[X][Y] > check[x][y] + nextTime)) {
					check[X][Y] = check[x][y] + nextTime;
					q.push({ X,Y });
				}
			}
		}
	}
}

void bfs2()
{
	memset(back, -1, sizeof(back));
	queue<pair<int, int>> q;
	
    q.push({1, 1});
	back[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
        for (int i = 0; i < 4; i++) {
			int X = x + pos_x[i];
			int Y = y + pos_y[i];
			if (X < 1 || Y < 1 || X > N || Y > M)
                continue;
			if (abs(p[X][Y] - p[x][y]) > T)
                continue; //높이차가 T보다 크면 불가능
			if (p[x][y] > p[X][Y]) {
				int nextTime = (p[x][y] - p[X][Y]) * (p[x][y] - p[X][Y]);
				if (back[x][y] + nextTime <= D 
                        && (back[X][Y] == -1 || back[X][Y] > back[x][y] + nextTime)) {
					back[X][Y] = back[x][y] + nextTime;
					q.push({ X,Y });
				}
			}
			else {
				if (back[x][y] + 1 <= D 
                        && (back[X][Y] == -1 || back[X][Y] > back[x][y] + 1)) {
					back[X][Y] = back[x][y] + 1;
					q.push({ X,Y });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> T >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char a;
			cin >> a;
			if ('A' <= a && a <= 'Z') p[i][j] = (a - 'A');
			else p[i][j] = (a - 'a' + 26);
		}
	}

	bfs(); //호텔 -> 등산
	bfs2(); //산->호텔

	res = p[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (check[i][j] != -1 && back[i][j] != -1
                    && check[i][j] + back[i][j] <= D) {
				res = max(res, p[i][j]);
			}
		}
	}

	cout << res;
}
