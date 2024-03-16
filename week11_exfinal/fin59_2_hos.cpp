#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    h *= 2;
    vector<vector<int>> graph(n + 1);
    vector<int> hospitals;
    vector<int> hospitals_type;
    vector<bool> global_visited(n, false);
    int count = 0;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        hospitals.push_back(a);
    }
    // for (auto x : hospitals) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        hospitals_type.push_back(2 - a);
    }
    // for (auto x : hospitals_type) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // for (auto x : graph) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < k; i++) {
        queue<pair<int, int>> q;
        q.push({hospitals[i], 0});
        vector<bool> visited(n, false);
        visited[hospitals[i]] = true;
        if (!global_visited[hospitals[i]]) {
            count++;
            global_visited[hospitals[i]] = true;
            // cout << "fist " << hospitals[i] << "\n";
        }
        while (!q.empty()) {
            auto it = q.front();
            int u = it.first;
            int w = it.second;
            q.pop();
            // cout << "cur " << u << "\n";
            for (auto x : graph[u]) {
                if (!visited[x] && hospitals_type[i] + w <= h) {
                    visited[x] = true;
                    if (!global_visited[x]) {
                        count++;
                        global_visited[x] = true;
                        // cout << "me " << x << " " << hospitals_type[i] + w
                        //      << " " << h << "\n";
                    }
                    if (hospitals_type[i] * 2 + w <= h) {
                        q.push({x, hospitals_type[i] + w});
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}