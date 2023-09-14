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
            if ((check & (1 << (arr[i][j] - 'a') ) ) == 0) // 못읽는게 나왔으면 까고 탈출
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
    if (depth == K - 5) // 갯수가 다 찼으면
    {
        ret = max(ret, cnt_word()); // 계산후 갱신
        return ;
    }

    for (int i = now; i < 26; i++)
    {
        if (( check & (1 << i) ) == 0) // 아직 비트마스킹 안되어있으면
        {
            check |= (1 << i); // 비트마스킹 해주고
            back_in_the_time(depth + 1, i + 1); // 탐색
            check &= ~(1 << i); // 비트마스킹 빼주기
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
    check |= 1 << ('c' - 'a'); // 단어 앞뒤로들어갈 알파벳 비트마스킹
    if (K >= 5) // 배울 단어가 5개 이상이여야 탐색시작
        back_in_the_time(0, 0);
    cout << ret;
}
