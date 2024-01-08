#include <bits/stdc++.h>

using namespace std;

int bfs(int s, int t, vector<vector<pair<int, int>>> graph, int color) {
    queue<int> q;
    q.push(s);
    vector<int> count(graph.size() + 1, -1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count[node]++;
        if (node == t) {
            cout << "\n";
            return count[node];
        }
        for (auto x : graph[node]) {
            if (x.second == color) {
                continue;
            }
            if (count[x.first] == -1) {
                count[x.first] = count[node];
                q.push(x.first);
            }
        }
    }
    return INTMAX_MAX;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> graph(n + 1);
    int result = INTMAX_MAX;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    result = min(bfs(s, t, graph, 1), bfs(s, t, graph, 2));
    if (result == INTMAX_MAX) {
        cout << -1;
    } else {
        cout << result;
    }
    return 0;
}
