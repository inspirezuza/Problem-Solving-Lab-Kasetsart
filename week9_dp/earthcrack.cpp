#include <bits/stdc++.h>

using namespace std;

int earthcrack() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> maze(m + 2, vector<int>(n + 2, 2000000));
    vector<vector<int>> dp(m + 2, vector<int>(n + 2, 2000000));
    int a;
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> a;
            maze[i][j] = a;
        }
    }

    for (int j = 0; j < n + 2; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int mintop =
                min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
            dp[i][j] = maze[i][j] + mintop;
        }
    }

    int ans = INT_MAX;
    for (int j = 1; j < n + 1; j++) {
        ans = min(ans, dp[m][j]);
    }
    cout << ans << "\n";
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        earthcrack();
    }
    return 0;
}