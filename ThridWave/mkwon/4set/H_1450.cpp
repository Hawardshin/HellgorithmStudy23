#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
long long arr[31];
long long cnt = 0;

vector<long long> left_sum;
vector<long long> right_sum;

void left(long long s, long long sum) {
    if (s == N / 2) {
        left_sum.push_back(sum);
        return;
    }
    left(s + 1, sum);
    left(s + 1, sum + arr[s]);
}
void right(long long s, long long sum) {
    if (s == N) {
        right_sum.push_back(sum);
        return;
    }
    right(s + 1, sum);
    right(s + 1, sum + arr[s]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> arr[i];

    left(0, 0);
    right(N / 2, 0);
    sort(right_sum.begin(), right_sum.end());

    for (int i = 0; i < left_sum.size(); i++) {
        cnt += upper_bound(right_sum.begin(), right_sum.end(), C - left_sum[i]) - right_sum.begin();
    }
    cout << cnt;

    return 0;
}
