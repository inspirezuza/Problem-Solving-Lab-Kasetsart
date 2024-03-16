#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            for (int k = 0; k < n; k++) {
                if (k == i) {
                    continue;
                }
                result[i][j] += abs(maze[i][j] - maze[k][j]);
            }
            for (int k = 0; k < m; k++) {
                if (k == j) {
                    continue;
                }
                result[i][j] += abs(maze[i][j] - maze[i][k]);
            }
        }
    }
    float minans = INT_MAX;
    int ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] < minans) {
                minans = result[i][j];
                ans = maze[i][j];
                // cout << "now " << minans << " " << ans << "\n";
            }
        }
    }

    cout << ans;
    return 0;
}