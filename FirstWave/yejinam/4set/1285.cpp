#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n;
vector<string> board;
int ret = 2147483647;

int back_in_the_time(int row)
{
	int ret = 0;
	for (int j = 0; j < n; j++)
	{
		int h = 0;
		int t = 0;
		for (int i = 0; i < n; i++)
		{
			if (((row >> i) & 1) == 1)
			{
				if (board[i][j] == 'H')
					t++;
				else
					h++;
			}
			else
			{
				if (board[i][j] == 'H')
					h++;
				else
					t++;
			}
		}
		ret += min(h, t);
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		board.push_back(input);
	}

	for (int i = 0; i < pow(2, n) - 1; i++)
	{
		ret = min(ret, back_in_the_time(i));
	}

	cout << ret;

	return 0;
}

