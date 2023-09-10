#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int arr[1024];
vector<int> tree[1000];

void divide(int start, int end, int h)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    tree[h].push_back(arr[mid]);

    divide(start, mid, h + 1);
    divide(mid + 1, end, h + 1);
}


int main()
{
    cin >> N;
    int num = pow(2, N) - 1;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    divide(0, num - 1, 0);

    tree[N - 1].push_back(arr[num - 1]);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
             cout << tree[i][j] << " ";
        cout << "\n";
    }
}
