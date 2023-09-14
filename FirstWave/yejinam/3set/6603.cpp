#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[13];
int back[6];
int check[13];

void print_back()
{
    for(int i = 0; i < 6 ; i++)
        cout << back[i] << " ";
    cout << "\n";
}

void back_in_the_time(int depth, int now)
{
    if (depth == 6)
    {
        print_back();
        return ;
    }

    for (int i = now; i < N; i++)
    {
        if (check[i] == 1)
            continue;
        back[depth] = arr[i];
        check[i] = 1;
        back_in_the_time(depth + 1, i + 1);
        check[i] = 0;
    }

}

int main()
{
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        back_in_the_time(0, 0);
        cout << "\n";
    }
}
