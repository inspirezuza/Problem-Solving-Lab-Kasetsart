#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    priority_queue<int> pq1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    int count = 0, starng = 0;

    pq1.push(0);
    while (!pq.empty()) {
        // cout << pq.top().first << " " << pq.top().second << "\n";
        count += pq.top().second;

        starng = count - pq.top().first;
        pq1.push(starng - 10);
        pq.pop();
        cout << starng - 10 << "\n";
    }
    cout << (pq1.top()) * 1000;
}