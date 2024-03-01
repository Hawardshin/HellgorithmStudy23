#include <climits>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> result1;
vector<int> result2;
typedef long long ll;
ll l, h, n, q;
bool check(long long mid) {
    ll cnt = q;
    for (int i = 0; i < v.size(); i++) {
        cnt += mid / v[i];
    }
    return cnt >= n;
}
int main() {
    l = 1;
    h = 60000000000;  // 놀이기구 하나에 운행시간 30 * 사람수 최대
    cin >> n;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    if (n <= q) {  // 사람수가 놀이기구수와 같거나 작다면 바로 출력
        cout << n;
        return 0;
    }
    ll time = 0;
    while (l <= h) {
        long long mid = (l + h) / 2;
        if (check(mid)) {
            h = mid - 1;
            time = mid;
        } else
            l = mid + 1;
    }
    ll ch = q;
    for (int i = 0; i < q; i++) {  // time-1 초에 타러간 아이들 숫자
        ch += (time - 1) / v[i];
    }
    for (int i = 0; i < q; i++) {  // time초에 타러가는 아이들 숫자 갱신
        if (time % v[i] == 0) ch++;
        if (ch == n) {  // 마지막 아이가 타러 들어가는 놀이기구 번호
            cout << i + 1 << "\n";
            break;
        }
    }
}