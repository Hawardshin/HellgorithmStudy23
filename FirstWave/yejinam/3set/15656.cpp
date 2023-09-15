#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int back[9];

void print_back()
{
    for(int i = 0; i < M ; i++)
        cout << back[i] << " ";
    cout << "\n";
}

void back_in_the_time(int depth)
{
    if (depth == M)
    {
        print_back();
        return ;
    }

    for (int i = 0; i < N; i++)
    {
        back[depth] = arr[i];
            back_in_the_time(depth + 1);
    }

}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    back_in_the_time(0);
}
