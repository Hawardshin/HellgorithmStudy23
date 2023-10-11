#include <iostream>

using namespace std;

int N, M, arr[100001], check[100001];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        arr[i] = i;

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        arr[u]++, arr[v]--;
    }

    for (int i = 1; i <= N; i++)
    {
        if (check[arr[i]] == 1)
            cout << "-1";
        check[arr[i]] = 1;
    }

    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
}
