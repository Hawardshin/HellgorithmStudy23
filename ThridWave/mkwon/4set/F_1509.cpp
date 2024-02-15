#include <algorithm>
#include <iostream>
#define INF 2147483647

using namespace std;

int n, m;
string str;
int tab[2505][2505];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    // 0
    for (int i = 0; i < str.length(); i++) tab[i][i] = 1;
    // 1
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i + 1]) tab[i][i + 1] = 1;
    }
    // 2~
    for (int j = 2; j < str.length(); j++) {
        for (int i = 0; i < str.length() - j; i++) {
            if (str[i] == str[i + j] && tab[i + 1][i + j - 1]) tab[i][i + j] = 1;
        }
    }

    int res[2505];
    for (int i = 0; i < str.length(); i++) {
        res[i] = INF - 5;
        for (int j = 0; j <= i; j++) {
            if (tab[j][i] == 1) {
                res[i] = min(res[i], res[j - 1] + 1);
            }
        }
    }

    cout << res[str.length() - 1];

    return 0;
}
