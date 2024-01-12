#include <bits/stdc++.h>

using namespace std;

bool isBipartite(queue<int> &q, vector<vector<int>> graph, vector<int> &color) {

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : graph[node]) {
            if (color[x] == -1) {
                q.push(x);
                color[x] = 1 - color[node];
            }
            if (color[x] == color[node]) {
                return false;
            }
        }
    }

    return true;
}

bool removePairCheck(vector<pair<int, int>> ttt, int k, int m, int n) {
    vector<vector<int>> graph(n + 1, vector<int>(0));
    vector<int> color(n + 1, -1);
    for (int i = 1; i < m + 1; i++) {
        if (i == k) {
            continue;
        }
        int a = ttt[i].first;
        int b = ttt[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    for (int i = 1; i < n + 1; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            if (!isBipartite(q, graph, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ttt(m + 1, pair<int, int>(0, 0));
    for (int i = 1; i < m + 1; i++) {
        int a, b;
        cin >> a >> b;
        ttt[i].first = a;
        ttt[i].second = b;
    }

    for (int k = 1; k < n + 1; k++) {
        if (removePairCheck(ttt, k, m, n)) {
            cout << ttt[k].first << " " << ttt[k].second;
            break;
        }
    }
    return 0;
}