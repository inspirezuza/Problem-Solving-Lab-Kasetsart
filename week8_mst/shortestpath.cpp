#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int s, int n, vector<vector<pair<int, int>>> graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> dist(n + 1, INT_MAX);
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x : graph[u]) {
            int v = x.first;
            int w = x.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    vector<int> answer = shortestPath(1, n, graph);
    cout << answer[n];
    return 0;
}