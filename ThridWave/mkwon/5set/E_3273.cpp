#include <algorithm>
#include <iostream>

using namespace std;

int n, m, arr[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;

    sort(arr, arr + n);

    int res = 0, i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == m) {
            res++;
            i++;
        } else if (arr[i] + arr[j] < m)
            i++;
        else if (arr[i] + arr[j] > m)
            j--;
    }
    cout << res;

    return 0;
}