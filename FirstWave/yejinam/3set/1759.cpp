#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
char back[15];

int is_pos()
{
    int gather = 0;
    for (int i = 0; i < L; i++)
        if (back[i] == 'a' || back[i] == 'e' || back[i] == 'i'
                || back[i] == 'o' || back[i] == 'u')
            gather++;
    if (gather >= 1 && L - gather >= 2)
        return 1;
    return 0;
}

void print_back()
{
    for (int i = 0; i < L; i++)
        cout << back[i];
    cout << "\n";
}

void back_in_the_time(int depth, int now)
{
    if (depth == L && is_pos())
    {
        print_back();
        return ;
    }
    for (int i = now; i < C; i++)
    {
        back[depth] = arr[i];
        back_in_the_time(depth + 1, i + 1);
    }
}

int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> arr[i];
    sort(arr, arr + C);
    back_in_the_time(0, 0);
}
