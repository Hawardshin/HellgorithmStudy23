#include <algorithm>
#include <iostream>

using namespace std;

long long x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    long long z = y * 100 / x;
    if (z >= 99) {
        cout << "-1";
        return 0;
    }

    int left = 0, right = 1000000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        int temp = (y + mid) * 100 / (x + mid);

        if (z < temp)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left;

    return 0;
}
