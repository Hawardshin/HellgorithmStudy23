#include <iostream>

using namespace std;

int N, M;
int dp[41];
int vip[41];
int main()
{
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> vip[i];
    vip[M + 1] = N + 1;
    int ret = 1 ;


    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp [i - 2];

    
    for (int i = 1; i <= M + 1; i++)
        ret *= dp[vip[i] - vip[i - 1] - 1];

    cout << ret;
}
