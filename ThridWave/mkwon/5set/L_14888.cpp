#include <algorithm>
#include <iostream>

using namespace std;

int n, m, arr[15], op[15];
int Max = -1000000005, Min = 1000000005;
// 0 : +, 1 : -, 2 : *, 3 : /

int cal() {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        if (op[i - 1] == 0)
            res = res + arr[i];
        else if (op[i - 1] == 1)
            res = res - arr[i];
        else if (op[i - 1] == 2)
            res = res * arr[i];
        else if (op[i - 1] == 3)
            res = res / arr[i];
    }
    return res;
}

void loop(int a, int b, int c, int d, int cnt) {
    if (cnt == n - 1) {
        int temp = cal();
        if (temp > Max) Max = temp;
        if (temp < Min) Min = temp;
        return;
    }

    if (a > 0) {
        op[cnt] = 0;
        loop(a - 1, b, c, d, cnt + 1);
    }
    if (b > 0) {
        op[cnt] = 1;
        loop(a, b - 1, c, d, cnt + 1);
    }
    if (c > 0) {
        op[cnt] = 2;
        loop(a, b, c - 1, d, cnt + 1);
    }
    if (d > 0) {
        op[cnt] = 3;
        loop(a, b, c, d - 1, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    loop(a, b, c, d, 0);
    cout << Max << "\n" << Min;

    return 0;
}
