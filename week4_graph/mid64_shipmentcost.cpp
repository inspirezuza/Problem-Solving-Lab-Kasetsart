#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    vector<int> count(n + 1, -2);

    while (s--) {
        int factory;
        cin >> factory;
        q.push(factory);
        count[factory] = -1;
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count[node]++;
        for (auto x : graph[node]) {
            if (count[x] == -2) {
                count[x] = count[node];
                q.push(x);
            }
        }
    }
    while (t--) {
        int ans;
        cin >> ans;
        cout << count[ans] << "\n";
    }
    return 0;
}