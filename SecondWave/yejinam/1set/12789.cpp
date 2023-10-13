#include <iostream>
#include <stack>
#include <queue>

using namespace std;
 
int N;
int student[1001];
stack<int> s;
queue<int> q;
vector<int> v;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		q.push(n);
	}

	int order = 1;
	while (!q.empty()) 
	{
		if (q.front() == order)
		{
			v.push_back(order); // 순서대로 먹는경우
			q.pop(); 
			order++;
		}
		else if (!s.empty() && s.top() == order)
		{
			v.push_back(order);
			s.pop();
			order++;
		}
		else
		{
			s.push(q.front());
			q.pop();
		}
	}

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}


	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i  + 1])
		{
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";


}
