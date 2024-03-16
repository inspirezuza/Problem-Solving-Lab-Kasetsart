#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> graph(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = -1;
    for (int i = 1; i < n + 1; i++) {
        int count = 1;
        queue<pair<int, int>> q;
        q.push({i, 0});
        vector<bool> visited(n + 1, false);
        visited[i] = true;
        while (!q.empty()) {
            auto node = q.front();
            int u = node.first;
            int w = node.second;
            q.pop();
            for (auto x : graph[u]) {
                if (!visited[x] && w + 1 <= h) {
                    count++;
                    visited[x] = true;
                    q.push({x, w + 1});
                }
            }
        }
        ans = max(count, ans);
    }
    cout << ans;
    return 0;
}