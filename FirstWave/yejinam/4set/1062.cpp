#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
string arr[50];
int check = 0;
int ret = 0;

int cnt_word()
{
    int cnt = N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 4; j < arr[i].size() - 4; j++)
        {
            if ((check & (1 << (arr[i][j] - 'a') ) ) == 0)
            {
                cnt --;
                break;
            }
        }
    }

    return cnt;
}

void back_in_the_time(int depth, int now)
{
    if (depth == K - 5)
    {
        ret = max(ret, cnt_word());
        return ;
    }

    for (int i = now; i < 26; i++)
    {
        if (( check & (1 << i) ) == 0)
        {
            char a = i + 'a';
            check |= (1 << i);
            back_in_the_time(depth + 1, i + 1);
            check &= ~(1 << i);
        }
    }
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    check |= 1 << ('a' - 'a');
    check |= 1 << ('n' - 'a');
    check |= 1 << ('t' - 'a');
    check |= 1 << ('i' - 'a');
    check |= 1 << ('c' - 'a');
    if (K >= 5)
        back_in_the_time(0, 0);
    cout << ret;
}
