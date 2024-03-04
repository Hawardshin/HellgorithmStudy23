#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    for (int i = s.size() - 1; i >= 0;) {
        if (i >= 2 && s[i - 2] == 'c' && s[i - 1] == 'h' && s[i] == 'u') {
            i -= 3;
        } else if (s[i - 1] == 'k' && s[i] == 'a') {
            i -= 2;
        } else if (s[i - 1] == 'p' && s[i] == 'i') {
            i -= 2;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}