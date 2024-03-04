#include <algorithm>
#include <iostream>

using namespace std;
int num[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if (a > b) {
        string temp = a;
        a = b;
        b = temp;
    }

    for (int i = 0; i < a.length(); i++) num[i] = a[a.length() - 1 - i] - '0';

    for (int i = 0; i < b.length(); i++) {
        int n = b[b.length() - 1 - i] - '0';
        num[i] += n;
        if (num[i] >= 10) {
            int temp = num[i];
            num[i] = temp % 10;
            num[i + 1] += temp / 10;
        }
    }

    int m = max(a.length(), b.length());
    if (num[m] != 0) m++;
    for (int i = m - 1; i >= 0; i--) cout << num[i];

    return 0;
}