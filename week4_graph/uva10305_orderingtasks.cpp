#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int a, b;
        vector<vector<int>> graph(n + 1);
        vector<int> inorder(n + 1, 0);
        queue<int> q;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            inorder[b]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (inorder[i] == 0) {
                inorder[i]--;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            inorder[node]--;
            cout << node << " ";
            for (auto x : graph[node]) {
                if (inorder[x] > 0) {
                    inorder[x]--;
                }
                if (inorder[x] == 0) {
                    q.push(x);
                }
            }
        }
        cout << "\n";
    }
    return 0;
}