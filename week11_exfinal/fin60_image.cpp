#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, r;
    cin >> m >> n >> r;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pair<pair<int, int>, int>> q;
            q.push({{i, j}, 0});
            int sum = 0;
            int count = 0;
            while (!q.empty()) {
                auto front = q.front();
                int x = front.first.first;
                int y = front.first.second;
                int w = front.second;
                q.pop();
                if (visited[x][y])
                    continue;   // Skip if visited
                sum += maze[x][y];
                count++;
                visited[x][y] = true;
                if (w + 1 > r)
                    continue;
                if (x > 0)
                    q.push({{x - 1, y}, w + 1});
                if (y < m - 1)
                    q.push({{x, y + 1}, w + 1});
                if (y > 0)
                    q.push({{x, y - 1}, w + 1});
                if (x < n - 1)
                    q.push({{x + 1, y}, w + 1});
            }
            dp[i][j] = sum / count;
        }
    }

    for (auto &row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
