// 참고했읍니다 블로그 만만세
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int ret = 0;
void simul(int pos, int board[20][20])
{
    queue<int> q;
    if (pos == 0) // 좌
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }
            int index = 0;
            while (q.size() != 0)
            {
                if (board[i][index] == 0) // 빈칸이면 그냥 넣기
                    board[i][index] = q.front();
                else if (board[i][index] == q.front()) // 같으면 더해주고 다음칸
                {
                    board[i][index] += q.front(); 
                    index++;
                }
                else // 다르면 다음칸에 넣기
                {
                    index++;
                    board[i][index] = q.front();
                }
                q.pop();
            }
        }
    }
    else if (pos == 1) // 우
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; 0 <=  j; j--)
            {
                if (board[i][j] != 0)
                    q.push(board[i][j]);
                board[i][j] = 0;
            }
            int index = N - 1;
            while (q.size() != 0)
            {
                if (board[i][index] == 0)
                    board[i][index] = q.front();
                else if (board[i][index] == q.front())
                {
                    board[i][index] += q.front();
                    index--;
                }
                else
                {
                    index--;
                    board[i][index] = q.front();
                }
                q.pop();
            }
        }
    }
    else if (pos == 2) // 상
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[j][i] != 0)
                    q.push(board[j][i]);
                board[j][i] = 0;
            }
            int index = 0;
            while (q.size() != 0)
            {
                if (board[index][i] == 0)
                    board[index][i] = q.front();
                else if (board[index][i] == q.front())
                {
                    board[index][i] += q.front();
                    index++;
                }
                else
                {
                    index++;
                    board[index][i] = q.front();
                }
                q.pop();
            }
        }
    }
    else // 하
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; 0 <= j; j--)
            {
                if (board[j][i] != 0)
                    q.push(board[j][i]);
                board[j][i] = 0;
            }
            int index = N - 1;
            while (q.size() != 0)
            {
                if (board[index][i] == 0)
                    board[index][i] = q.front();
                else if (board[index][i] == q.front())
                {
                    board[index][i] += q.front();
                    index--;
                }
                else
                {
                    index--;
                    board[index][i] = q.front();
                }
                q.pop();
            }
        }
    }


}

int findMax(int board[20][20])
{
    int num = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num = max(num, board[i][j]);
    return num;
}

void back_in_the_time(int depth, int board[20][20])
{
    if (depth == 5)
    {
        ret = max(ret, findMax(board));
        return;
    }
    
    for(int i = 0; i < 4; i++)
    { 
        int tmp[20][20];
        memcpy (tmp, board, sizeof(tmp));
        simul(i, tmp);
        back_in_the_time(depth + 1, tmp);
    }
}

int main()
{
    int board[20][20];
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    back_in_the_time(0, board);
    cout << ret;
}
