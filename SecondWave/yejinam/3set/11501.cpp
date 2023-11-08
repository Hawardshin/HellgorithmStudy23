#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        int m;
        vector<int> v;
        
        cin >> m;
        for(int i = 0; i < m; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        long long result = 0;
        int max_num = -1;

        for(int i = m - 1; i >= 0; i--) {
            max_num = max(max_num, v[i]);
            result += max_num - v[i];
        }

        cout << result << "\n";
    }
}
