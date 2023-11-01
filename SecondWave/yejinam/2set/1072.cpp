#include "iostream"

using namespace std;

double X, Y, Z;
int main()
{
	cin >> X >> Y;
	int Z = (Y * 100) / X;
	int n = 0;
	int ans=-1;
	if (Z >= 99)
	{
		cout << -1;
		return 0;
	}
	int min = 1, max = X; // 최대는 X

	while (min <= max)
	{
		int mid = (min + max) / 2; // 이분탐색하면서
		double x = X + mid;
		double y = Y + mid;
		int z = (y * 100) / x;

		if (z == Z) // 값이 그대로면 min up
			min = mid + 1;
		else // 바뀌었으면 max down
		{
			ans = mid;
			max = mid - 1;
		}
	}

	cout << ans;
}