#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

int N, M, K;
int pos_x[4] = {0, -1, 0, 1}; // 좌 상 우 하
int pos_y[4] = {-1, 0, 1, 0};
int inf[6][3];
int check[6];
int ret = 2147482647;

int findMin(int arr[50][50]) //최솟 줄 찾아서 리턴
{
    int total = 2147483647;
    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j < M; j++)
        {
            tmp += arr[i][j];
        }
        total = min(total, tmp);
    }


    return total;
}

void rot(int arr[50][50], int x, int y, int l)
{
    deque<int> dq;
    int X = x;
    int Y = y;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < l; j++)
        {
            dq.push_back(arr[X][Y]); // 좌상우하로 돌면서 덱에 집어넣기 
            X += pos_x[i];
            Y += pos_y[i];
        }
    }
    dq.push_front(dq.back()); // 뒤에꺼 빼서 앞에넣기 
    dq.pop_back(); // 12345  -> 51234

    X = x;
    Y = y;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < l; j++)
        {
          arr[X][Y] = dq.front(); // 좌상우하 돌면서 배열에 집어넣기
          dq.pop_front();
          X += pos_x[i];
          Y += pos_y[i];
        }
    }
}

void back_in_the_time(int depth, int arr[50][50])
{
    if (depth == K)
    {
        ret = min(ret, findMin(arr));
        return ;
    }

    for (int i = 0; i < K; i++) // 최솟값 찾아서 갱신 
    {
        if (check[i] == 0) // 아직 시뮬 안돌렸다면
        {
            int tmp[50][50]; // 시뮬돌릴 배열선언

            memcpy(tmp, arr, sizeof(tmp)); // 값 복사
            for (int j = 1; j <= inf[i][2]; j++) // 시뮬레이션 돌리기
                rot(tmp, inf[i][0] - 1 + j, inf[i][1] - 1 + j, j * 2);
            check[i] = 1;
            back_in_the_time(depth + 1, tmp);
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    int arr[50][50];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++)
        cin >> inf[i][0] >> inf[i][1] >> inf[i][2];

    back_in_the_time(0, arr);
    cout << ret;
}
