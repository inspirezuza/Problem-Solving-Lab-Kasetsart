#include <bits/stdc++.h>

using namespace std;

int dfsMaze(int r,
            int c,
            int a,
            int b,
            vector<vector<int>> &visited,
            vector<vector<char>> maze,
            int key) {
    if (maze[r][c] == '#') {
        return 0;
    }
    if (maze[r][c] == 'O' && key == 1) {
        key--;
    } else if (maze[r][c] == 'O' && key == 0) {
        return 0;
    }
    visited[r][c] = 1;
    // cout << r << " " << c << " " << key << "\n";
    if (r == a && c == b) {
        return 1;
    }
    if (r < maze.size() - 1 && visited[r + 1][c] == 0) {
        if (dfsMaze(r + 1, c, a, b, visited, maze, key)) {
            return 1;
        }
    }
    if (c < maze.size() - 1 && visited[r][c + 1] == 0) {
        if (dfsMaze(r, c + 1, a, b, visited, maze, key)) {
            return 1;
        }
    }
    if (r > 0 && visited[r - 1][c] == 0) {
        if (dfsMaze(r - 1, c, a, b, visited, maze, key)) {
            return 1;
        }
    }
    if (c > 0 && visited[r][c - 1] == 0) {
        if (dfsMaze(r, c - 1, a, b, visited, maze, key)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, q;
    char c;
    cin >> n >> q;
    vector<vector<char>> maze(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            maze[i].push_back(c);
        }
    }

    // ถ้า dfs ทีเดียว แล้ว check จาก visited จะได้ O(n^2)
    // ซึ่งดีกว่า O(q*n^2)
    // แต่ขี้เกียจแก้ละ ชังมัน ส่งผ่านละ55555555
    while (q--) {
        int r, c, a, b;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        cin >> r >> c >> a >> b;
        if (dfsMaze(r - 1, c - 1, a - 1, b - 1, visited, maze, 1)) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << "\n";
        // for (auto x : visited) {
        //     for (auto y : x) {
        //         cout << y;
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    return 0;
}