#include <iostream>

using namespace std;

int t, n, bit;
string str;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> t;
    bit = 0;
    while (t--) {
        str.clear();
        cin >> str;
        if (str == "add")  // or 둘다 0이어야 0
        {
            cin >> n;
            bit |= (1 << n);
        } else if (str == "remove")  // 뒤집어서 and
        {
            cin >> n;
            bit &= ~(1 << n);
        } else if (str == "check")  // true ar flase
        {
            cin >> n;
            if (bit & (1 << n))
                cout << "1\n";
            else
                cout << "0\n";
        } else if (str == "toggle")  // xor 둘이 다르면 1
        {
            cin >> n;
            bit ^= (1 << n);
        } else if (str == "all") {
            bit = (1 << 21) - 1;
        } else if (str == "empty") {
            bit = 0;
        }
    }

    return 0;
}
