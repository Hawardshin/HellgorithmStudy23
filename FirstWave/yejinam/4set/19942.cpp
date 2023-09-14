#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int M[4];
int ingredients[15][5];

int back[15];
int ret[15];
int min_cost = 2147483647;

int is_pos()
{
    int total[4] = {0, 0, 0, 0};
    for (int i = 0; back[i]; i++) // 영양소 체크
    {
            total[0] += ingredients[back[i] - 1][0];
            total[1] += ingredients[back[i] - 1][1];
            total[2] += ingredients[back[i] - 1][2];
            total[3] += ingredients[back[i] - 1][3];
    }
    for (int i = 0; i < 4; i++)
    {
        if (total[i] < M[i]) // 덜찬게 있으면 0 반환
            return 0;
    }
    return 1;
}

void back_in_the_time(int depth, int now, int cost)
{
    if (is_pos() && cost <= min_cost) // 영양소 다찼고 더 적은 가격이라면 
    {
        if (cost < min_cost)
            memcpy(ret, back, sizeof(back));
        else if (memcmp(ret, back, sizeof(ret)) > 0)
            memcpy(ret, back, sizeof(back)); // 갱신
        min_cost = cost;
        return ;
    }

    if (now == N) // 끝까지 왔으면 종료
        return ;

    for (int i = now; i < N; i++)
    {
        back[depth] = i + 1;
        back_in_the_time(depth + 1, i + 1, cost + ingredients[i][4]);
        back[depth] = 0;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> M[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 5; j++)
            cin >> ingredients[i][j];

    back_in_the_time(0, 0, 0);
    if (min_cost == 2147483647)
        cout << -1 << endl;
    else
    {
        cout << min_cost << endl;
        for (int i = 0; ret[i]; i++)
            cout << ret[i] << " ";
        cout << endl;
    }
}
