#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, order[110];
bool plugged_in[110];
vector<int> plug;

int remove_one(int start) {
    int last = 0;
    for (int j = 0; j < plug.size(); ++j) {
        int p = plug[j];
        int idx = -1;
        for (int i = start; i <= K; ++i) {
            if (order[i] == p) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
            return p;
        else
            last = max(last, idx);
    }

    return order[last];
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; ++i) cin >> order[i];

    int res = 0;
    for (int i = 0; i < K; ++i) {
        int name = order[i];

        if (plugged_in[name])
            continue;
        else {
            if (N > 0) {
                plugged_in[name] = true;
                plug.push_back(name);
                N--;
            } else if (N == 0) {
                res++;

                int item = remove_one(i);
                plug.erase(remove(plug.begin(), plug.end(), item), plug.end());
                plugged_in[item] = false;
                plugged_in[name] = true;
                plug.push_back(name);
            }
        }
    }

    cout << res;

    return 0;
}