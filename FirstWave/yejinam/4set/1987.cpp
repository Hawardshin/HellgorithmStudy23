#include <iostream>

using namespace std;

int R, C;
char board[20][20];
int alphabet[26];
int pos_x[4] = {0, 1, 0, -1};
int pos_y[4] = {1, 0, -1, 0};
int ret = 0;

int in_range(int x, int y)
{
	if (x < 0 || R <= x)
		return 0;
	if (y < 0 || C <= y)
		return 0;
	return 1;
}

void back_in_the_time(int depth, int x, int y)
{
	if (ret < depth)
		ret = depth;
	for(int i = 0; i < 4; i++)
	{
		int X = x + pos_x[i];
		int Y = y + pos_y[i];
		if (in_range(X, Y) && alphabet[board[X][Y] - 'A'] == 0)
		{
			alphabet[board[X][Y] - 'A'] = 1;
			back_in_the_time(depth + 1, X, Y);
			alphabet[board[X][Y] - 'A'] = 0;
		}
	}

}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	alphabet[board[0][0] - 'A'] = 1;
	back_in_the_time(1, 0, 0);
	cout << ret;
}
