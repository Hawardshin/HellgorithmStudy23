#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string.h>

using namespace std;

int result[21];

int main()
{

	ios :: sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	string command;
	int inum;
	for (int i=0; i< num; i++)
	{
		cin >> command;
		if (command == "add")
		{
			cin >> inum;
			result[inum] = 1;
		}
		else if (command == "remove")
		{
			cin >> inum;
			result[inum] = 0;
		}
		else if (command == "check")
		{
			cin >> inum;
			if (result[inum])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "toggle")
		{
			cin >> inum;
			if (result[inum])
				result[inum ] =0;
			else
				result[inum] = 1;
		}
		else if (command == "all")
		{
			for (int i=1; i<= 20; i++)
				result[i] =1;

		}
		else if (command == "empty")
		{
			for (int i=1; i<= 20; i++)
				result[i] =0;

		}
	}
}