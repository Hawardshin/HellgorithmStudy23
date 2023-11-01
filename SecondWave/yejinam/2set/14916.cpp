#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int five = 0, two = 0;
	int ret = 0;

	five = n / 5; // 5의 최대구하기
	n %= 5;

	two += n / 2;
	n %= 2;

	while (n) // 안나누어 떨어질때까지
	{
		five--; // 5 뻬고
		n += 5;
		two += n / 2; // 2로 채우기
		n %= 2;
		if (five < 0) 
			break;
	}
	if (five < 0)// 5 다 떨어졌으면 안되는 경우
		cout << -1;
	else
		cout << five + two << endl;
}