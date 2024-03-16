#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    queue<pair<int, int>> q;
    q.push({n - 1, 0});
    dp[n - 1][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int w = dp[x][y];
        q.pop();

        if (maze[x][y] == 'X') {
            continue;
        }

        if (x > 0 && maze[x - 1][y] != 'X' && w + 5 < dp[x - 1][y]) {
            q.push({x - 1, y});
            dp[x - 1][y] = w + 5;
        }
        if (y < m - 1 && maze[x][y + 1] != 'X' && w + 1 < dp[x][y + 1]) {
            q.push({x, y + 1});
            dp[x][y + 1] = w + 1;
        }
        if (y > 0 && maze[x][y - 1] != 'X' && w + 1 < dp[x][y - 1]) {
            q.push({x, y - 1});
            dp[x][y - 1] = w + 1;
        }
        if (x < n - 1 && maze[x + 1][y] != 'X' && w < dp[x + 1][y]) {
            q.push({x + 1, y});
            dp[x + 1][y] = w;
        }
    }

    if (dp[0][m - 1] == INT_MAX) {
        cout << "-1";
    } else {
        cout << dp[0][m - 1];
    }
    return 0;
}
