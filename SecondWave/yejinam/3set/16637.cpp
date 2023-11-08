#include <iostream>

using namespace std;

int n;
char form[20];
int ret = -987654321;
int calcul(int a, int b)
{
    if (form[(a + b) / 2] == '+')
        return form[a] + form[b];
    if (form[(a + b) / 2] == '-')
        return form[a] - form[b];
    if (form[(a + b) / 2] == '*')
        return form[a] * form[b];
}

void dfs(int depth, int sum)
{
    if (depth >= n && ret < sum)
    {
        ret = sum;
        return;
    }

    if (form[depth] == '+')
    {
        dfs(depth + 2, sum + form[depth + 1]);
        if (depth + 4 <= n)
            dfs(depth + 4, sum + calcul(depth + 1, depth + 3));
    }

    if (form[depth] == '-')
    {
        dfs(depth + 2, sum - form[depth + 1]);
        if (depth + 4 <= n)
            dfs(depth + 4, sum - calcul(depth + 1, depth + 3));
    }

    if (form[depth] == '*')
    {
        dfs(depth + 2, sum * form[depth + 1]);
        if (depth + 4 <= n)
            dfs(depth + 4, sum * calcul(depth + 1, depth + 3));
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> form[i];
        if (i % 2 == 0)
            form[i] -= '0';

    }

    if (n == 1)
    {
        ret = form[0];
    }
    if (n >= 3)
    {
        dfs(1, form[0]);
        dfs(3, calcul(0, 2));
    }
    cout << ret;
}
