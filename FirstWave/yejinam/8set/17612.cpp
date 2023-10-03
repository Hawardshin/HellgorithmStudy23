#include<iostream>
#include<queue>

// 설명을 봐도 모르겐네....

using namespace std;
 
struct checkout
{
    int num; // 카운터 숫자
    int time; // 걸리는 시간
};
 
struct customer
{
    int id;
    int checkout_num;
    int exit_time;
};
 
struct checkout_cmp
{
    bool operator()(checkout &a, checkout &b)
    {
        if (a.time == b.time)
            return a.num > b.num;
        return a.time > b.time;
    }
};
 
struct customer_cmp
{
    bool operator()(customer &a, customer&b)
    {
        if (a.exit_time==b.exit_time) 
            return a.checkout_num < b.checkout_num;
        return a.exit_time > b.exit_time;
    }
};
 
int N, K, id, w, t, c_num, coeff=1;
long long ans;
priority_queue<checkout, vector<checkout>, checkout_cmp> pq_in;
priority_queue<customer, vector<customer>, customer_cmp> pq_out;
 
int main()
{
    cin >> N >> K;
 
    for (int i = 1; i <= K; i++)
        pq_in.push({i, 0});
 
    for (int i = 0; i < N; i++)
    {
        cin >> id >> w;
        
        t = pq_in.top().time + w;
        c_num = pq_in.top().num;
 
        pq_in.pop();
        pq_in.push({c_num, t});
        pq_out.push({id, c_num, t});
    }
 
    while (!pq_out.empty())
    {
        ans += (long long) coeff * pq_out.top().id;
        coeff++;
        pq_out.pop();
    }
 
    cout << ans;
 
    return 0;
}
