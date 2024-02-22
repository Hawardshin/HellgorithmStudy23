#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 300001
using namespace std;

int N, K;

pair<int, int> jew[MAX];
int bag[MAX];
priority_queue<int, vector<int>, less<int>> pq;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> jew[i].first >> jew[i].second;
    for (int i = 0; i < K; ++i) cin >> bag[i];

    sort(jew, jew + N);
    sort(bag, bag + K);

    long long sum = 0;
    for (int i = 0, j = 0; i < K; i++) {
        while (j < N && bag[i] >= jew[j].first) {
            pq.push(jew[j].second);
            j++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}
