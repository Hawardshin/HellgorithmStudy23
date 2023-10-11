#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
 
struct coordnate
{
    int x;
    int y;
};
 
int N, W;
int dp[1001][1001];
coordnate event[1001];
 
int get_distance(int x, int y, int X, int Y) 
{ 
    return abs(X - x) + abs(Y - y); 
}
 
int total_distance(int P1, int P2)
{
    if (P1 == W || P2 == W) // W를 맡았다면 종료
        return 0;

    if (dp[P1][P2] != -1) // 이전에 계산한 값이 있을시 리턴
        return dp[P1][P2];
    
    int next = max(P1, P2) + 1;
    int dist1, dist2;
 
    if (P1 == 0) 
        dist1 = get_distance(1, 1, event[next].x, event[next].y);
    else 
        dist1 = get_distance(event[P1].x, event[P1].y, event[next].x, event[next].y);
 
    if (P2 == 0) 
        dist2 = get_distance(N, N, event[next].x, event[next].y);
    else 
        dist2 = get_distance(event[P2].x, event[P2].y, event[next].x, event[next].y);
 
    int Result1 = dist1 + total_distance(next, P2);
    int Result2 = dist2 + total_distance(P1, next);
    dp[P1][P2] = min(Result1, Result2);
    
    return dp[P1][P2];
}
 
void route(int P1, int P2)
{
    if (P1 == W || P2 == W) 
        return;
    
    int next = max(P1, P2) + 1;
    int dist1, dist2;
 
    if (P1 == 0) 
        dist1 = get_distance(1, 1, event[next].x, event[next].y);
    else 
        dist1 = get_distance(event[P1].x, event[P1].y, event[next].x, event[next].y);
 
    if (P2 == 0) 
        dist2 = get_distance(N, N, event[next].x, event[next].y);
    else 
        dist2 = get_distance(event[P2].x, event[P2].y, event[next].x, event[next].y);
 
    if (dp[next][P2] + dist1 < dp[P1][next] + dist2)
    {
        cout << 1 << endl;
        route(next, P2);
    }
    else
    {
        cout << 2 << endl;
        route(P1, next);
    }
}
 
int main(void)
{
    cin >> N >> W;
    for (int i = 1; i <= W; i++)
        cin >> event[i].x >> event[i].y;
    
    memset(dp, -1, sizeof(dp));
    cout << total_distance(0, 0) << endl;
    route(0, 0);

    return 0;
}

