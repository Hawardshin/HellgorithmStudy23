#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    int now = 0;
    while (!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        if (now < x)
            now = x + y;
        else
            now += y;
    }

    cout << now;

    return 0;
}