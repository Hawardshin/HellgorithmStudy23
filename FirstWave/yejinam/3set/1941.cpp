#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int result = 0;
string arr[5];
int check_dfs[5][5];
int tmp[5][5];
int pos_x[4] = { 0, 1, 0, -1 };
int pos_y[4] = { 1, 0, -1, 0 };
int Y = 0;
int S = 0;

int bfs(int start_x, int start_y) {
	queue<pair<int, int> > queue;
	queue.push({start_x, start_y});
    int check_bfs[5][5];

    memset(check_bfs, 0, sizeof(check_bfs));
	check_bfs[start_x][start_y] = 1;
	int cnt = 1;

	while(queue.size() != 0) {
		pair<int, int> top = queue.front();
		int x = top.first;
		int y = top.second;
        queue.pop();

		for(int i = 0; i < 4; i++) {
			int X = x + pos_x[i];
			int Y = y + pos_y[i];

			if((0 <= X && X < 5 && 0 <= Y && Y < 5)
				&& check_dfs[X][Y] && check_bfs[X][Y] == 0) {
				check_bfs[X][Y] = 1;
				queue.push({X, Y});
				cnt++;
			}
		}
	}

	return cnt;
}

void dfs(int depth, int x, int y) {
	if (depth == 7) {
		if (bfs(x, y) == 7)
			result++;
		return;
	}

	for (int i = x; i < 5; i++)
    {
		for (int j = y; j < 5; j++)
        {
			if (check_dfs[i][j] == 0)
            {
				check_dfs[i][j] = 1;
                if (arr[i][j] == 'Y')
                    Y++;
                if (Y < 4)
				    dfs(depth + 1, i, j);
				check_dfs[i][j] = 0;
                if (arr[i][j] == 'Y')
                    Y--;
			}
		}
        y = 0;
    }
}

int main() {

	for (int i = 0; i < 5; i++)
		    cin >> arr[i];

	dfs(0, 0, 0);

	cout << result << endl;

	return 0;
}
