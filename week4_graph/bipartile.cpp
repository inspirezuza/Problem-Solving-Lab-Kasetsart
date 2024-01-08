#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, m;
    cin >> k;
    while (k--) {
        cin >> n >> m;
        vector<vector<int>> graph(n + 1, vector<int>(0));
        vector<int> color(n + 1, -1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        // Print out all values in graph
        // for (int i = 1; i <= n; i++) {
        //     cout << i << ": ";
        //     for (int j = 0; j < graph[i].size(); j++) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n";
        queue<int> q;
        q.push(1);
        color[1] = 0;
        bool isBipartile = true;
        while (!q.empty() && isBipartile) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartile = false;
                    break;
                }
            }
        }
        if (isBipartile) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}