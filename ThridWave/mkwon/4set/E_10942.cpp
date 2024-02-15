#include <algorithm>
#include <iostream>

using namespace std;

int n, num[2005], m;
int tab[2005][2005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];

    // 0
    for (int i = 1; i <= n; i++) tab[i][i] = 1;
    // 1
    for (int i = 0; i <= n; i++) {
        if (num[i] == num[i + 1]) tab[i][i + 1] = 1;
    }
    // 2~
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= n - j; i++) {
            if (num[i] == num[i + j] && tab[i + 1][i + j - 1]) tab[i][i + j] = 1;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << tab[a][b] << "\n";
    }

    return 0;
}
