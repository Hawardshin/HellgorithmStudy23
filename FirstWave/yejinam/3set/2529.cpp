#include <iostream>
#include <string.h>

using namespace std;

int N, first = 1;
char arr[9];
int ret[10];
int back[10];
int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void print_back()
{
    for(int i = 0; i <= N ; i++)
        cout << ret[i];
    cout << "\n";
}

int in_order(int depth)
{
    if (arr[depth] == '<')
        return (back[depth] < back[depth + 1]);
    else
        return (back[depth] > back[depth + 1]);
}

void back_in_the_time(int depth)
{
    if (depth == N + 1)
    {
        memcpy(ret, back, sizeof(ret));
        if (first == 1)
            print_back();
        first = 0;
        return ;
    }

    for (int i = 9; i >= 0; i--)
    {
        if (check[i] == 1)
            continue;
        back[depth] = i;
        check[i] = 1;
        if (depth == 0 || in_order(depth - 1))
            back_in_the_time(depth + 1);
        check[i] = 0;
    }

}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    back_in_the_time(0);
    print_back();
}
