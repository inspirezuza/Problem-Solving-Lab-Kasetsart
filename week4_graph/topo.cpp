#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i < n + 1; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (auto x : graph[node]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    // there is a better way
    // if result == n ? correct else no
    for (auto x : indegree) {
        if (x != 0) {
            cout << "no";
            return 0;
        }
    }

    for (auto x : result) {
        cout << x << "\n";
    }

    return 0;
}