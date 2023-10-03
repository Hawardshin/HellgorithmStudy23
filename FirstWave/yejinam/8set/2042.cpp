#include<iostream>
#include<vector>
#include<cmath>
 
typedef long long ll;
using namespace std;
 
int N, M, K;
vector<ll> arr;
vector<ll> tree;
vector<pair<int, pair<int, ll>>> cmd;
 
ll make_tree(int now, int start, int end)
{
    if (start == end)
        return tree[now] = arr[start];
    
    int mid = (start + end) / 2;

    ll l_sum = make_tree(now * 2, start, mid);
    ll r_sum = make_tree(now * 2 + 1, mid + 1, end);
    tree[now] = l_sum + r_sum;
    return tree[now];
}
 
ll sum(int now, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[now];
 
    int mid = (start + end) / 2;
    ll l_sum = sum(now * 2, start, mid, left, right);
    ll r_sum = sum(now * 2 + 1, mid + 1, end, left, right);
    return l_sum + r_sum;
}
 
void update_tree(int now, int start, int end, int index, ll diff)
{
    if (index < start || index > end)
        return;
    tree[now] = tree[now] + diff;
 
    if (start != end)
    {
        int mid = (start + end) / 2;
        update_tree(now * 2, start, mid, index, diff);
        update_tree(now * 2 + 1, mid + 1, end, index, diff);
    }
}
 
int main(void)
{

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cmd.push_back(make_pair(a, make_pair(b, c)));
    }

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    tree.resize(size);
    make_tree(1, 0, N - 1);
 
    for (int i = 0; i < cmd.size(); i++)
    {
        int command = cmd[i].first;
        if (command == 1) // 값바꾸기
        {
            int index = cmd[i].second.first - 1;
            ll value = cmd[i].second.second;
            ll diff = value - arr[index];
            arr[index] = value;
            update_tree(1, 0, N - 1, index, diff);
        }
        else // 계산하기
        {
            int index = cmd[i].second.first - 1;
            int index2 = cmd[i].second.second - 1;
            ll result = sum(1, 0, N - 1, index, index2);
            cout << result << endl;
        }
    }

    return 0;
}
