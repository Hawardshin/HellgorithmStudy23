#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int fruit[10001];
int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		cin >> fruit[i];

	sort(fruit, fruit + N);

	for (int i = 0; i < N; i++)
	{
		if(fruit[i] <= L)
			L++;
		else
			break;
	}

	cout << L;

}
