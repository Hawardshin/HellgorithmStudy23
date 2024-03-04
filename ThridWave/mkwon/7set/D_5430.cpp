#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        deque<int> dq;
        string p, str;
        int n, flag = 0, eflag = 0;
        cin >> p >> n >> str;

        string s = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9')
                s += str[i];
            else {
                if (s == "") continue;
                dq.push_back(stoi(s));
                s = "";
            }
        }

        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                if (flag)
                    flag = 0;
                else
                    flag = 1;
            } else if (p[i] == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    eflag = 1;
                    break;
                }
                if (flag)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (eflag) continue;

        cout << "[";
        if (flag) {
            while (!dq.empty()) {
                cout << *(dq.rbegin());
                dq.pop_back();
                if (!dq.empty()) cout << ",";
            }
        } else {
            while (!dq.empty()) {
                cout << *(dq.begin());
                dq.pop_front();
                if (!dq.empty()) cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}