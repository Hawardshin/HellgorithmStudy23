#include <iostream>
int N;
int M;
int board[9];
int arr[9];

void    yeji_swap(int arr[9], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void    yeji_sort(int arr[9], int N)
{
    int i;
    int j;

    i = 0;
    while(i < N)
    {
        j = i + 1;
        while(j < N)
        {
            if (arr[i] > arr[j])
                yeji_swap(arr, i, j);
            j++;
        }
        i++;
    }
}

void    print_board()
{
    int i;

    i = 0;

    while(i < M)
    {
        printf("%d ", board[i]);
        i++;
    }
    printf("\n");
}

int check(int depth)
{
    int i;
    int j;

    i = 0;
    while(i < depth)
    {
        j = i + 1;
        while(j < depth)
        {
            if (board[i] == board[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

void    dfs(int depth)
{
    int i = 0;

    if (depth == M && check(depth))
    {
        print_board();
        return ;
    }

    while(i < N)
    {
        board[depth] = arr[i];
        if (check(depth))
            dfs(depth + 1);
        i++;
    }
}


int main()
{
    int i;

    i = 0;
    std::cin >> N >> M;
    while(i < N)
    {
        std::cin >> arr[i];
        i++;
    }

    yeji_sort(arr, N);
    dfs(0);
}
