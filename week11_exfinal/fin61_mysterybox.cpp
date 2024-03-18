#include <bits/stdc++.h>

using namespace std;

void laser(int start,
           int x,
           int y,
           int direction,
           vector<int> &ans,
           vector<vector<int>> maze,
           int n) {

    if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
        ans[maze[x][y]] = start;
        ans[start] = maze[x][y];

        return;
    } else if (maze[x][y] == 0) {   // '.'
        if (direction == 1) {       // right
            laser(start, x, y + 1, 1, ans, maze, n);
        } else if (direction == 2) {   // up
            laser(start, x - 1, y, 2, ans, maze, n);
        } else if (direction == 3) {   // left
            laser(start, x, y - 1, 3, ans, maze, n);
        } else if (direction == 4) {   // down
            laser(start, x + 1, y, 4, ans, maze, n);
        }
    } else if (maze[x][y] == -1) {   // '/'
        if (direction == 1) {
            laser(start, x - 1, y, 2, ans, maze, n);
        } else if (direction == 2) {
            laser(start, x, y + 1, 1, ans, maze, n);
        } else if (direction == 3) {
            laser(start, x + 1, y, 4, ans, maze, n);
        } else if (direction == 4) {
            laser(start, x, y - 1, 3, ans, maze, n);
        }
    } else if (maze[x][y] == -2) {   // '\'
        if (direction == 1) {
            laser(start, x + 1, y, 4, ans, maze, n);
        } else if (direction == 2) {
            laser(start, x, y - 1, 3, ans, maze, n);
        } else if (direction == 3) {
            laser(start, x - 1, y, 2, ans, maze, n);
        } else if (direction == 4) {
            laser(start, x, y + 1, 1, ans, maze, n);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze(n + 2, vector<int>(n + 2, 0));
    vector<int> ans(n * 4 + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            char a;
            cin >> a;
            if (a == '.') {
                maze[i][j] = 0;
            } else if (a == '/') {
                maze[i][j] = -1;
            } else if (a == '\\') {
                maze[i][j] = -2;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        maze[i][0] = i;
        maze[n + 1][i] = char(i + n);
        maze[n - i + 1][n + 1] = i + n * 2;
        maze[0][n + 1 - i] = i + n * 3;
    }

    // for (auto x : maze) {
    //     for (auto y : x) {
    //         cout << y << "\t";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            laser(i, i, 1, 1, ans, maze, n);
        }
        if (ans[n + i] == 0) {
            laser(n + i, n, i, 2, ans, maze, n);
        }
        if (ans[n * 2 + i] == 0) {
            laser(n * 2 + i, n - i + 1, n, 3, ans, maze, n);
        }
        if (ans[n * 3 + i] == 0) {
            laser(n * 3 + i, 1, n + 1 - i, 4, ans, maze, n);
        }
    }
    for (int i = 1; i <= n * 4; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}