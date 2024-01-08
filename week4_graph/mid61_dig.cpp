#include <bits/stdc++.h>

using namespace std;

typedef struct Walk {
    int x;
    int y;
    int key;
    int count;
} Walk;

int main() {
    int n, m;
    int r, c, a, b;

    cin >> n >> m;
    cin >> r >> c >> a >> b;

    vector<vector<char>> maze(n);
    for (int i = 0; i < n; i++) {
        char c;

        for (int j = 0; j < m; j++) {
            cin >> c;
            maze[i].push_back(c);
        }
    }

    // ถ้าใช้ A* น่าจะดีกว่า แต่ขี้เกียจละ ทำ BFS นี้แหละ

    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<Walk> q;
    Walk start = {r - 1, c - 1, 1, 0};

    q.push(start);
    while (!q.empty()) {
        Walk node = q.front();
        q.pop();
        int r = node.x;
        int c = node.y;

        if (maze[r][c] == '#' || maze[r][c] == '*' || visited[r][c] != 0) {
            continue;
        }

        // cout << r << " " << c << " " << node.key << maze[r][c] << "\n";

        visited[r][c] = node.count + 1;

        if (r == a - 1 && c == b - 1) {
            // for (auto x : visited) {
            //     for (auto y : x) {
            //         cout << y;
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            cout << node.count;

            return 1;
        }
        if (r < maze.size() - 1 && visited[r + 1][c] == 0) {
            if (maze[r + 1][c] == '*' && maze[r + 2][c] == '.' &&
                visited[r + 2][c] == 0 && node.key == 1) {
                Walk next = {r + 2, c, node.key - 1, node.count + 2};
                q.push(next);
            } else {
                Walk next = {r + 1, c, node.key, node.count + 1};
                q.push(next);
            }
        }
        if (c < maze.size() - 1 && visited[r][c + 1] == 0) {
            if (maze[r][c + 1] == '*' && maze[r][c + 2] == '.' &&
                visited[r][c + 2] == 0 && node.key == 1) {
                Walk next = {r, c + 2, node.key - 1, node.count + 2};
                q.push(next);
            } else {
                Walk next = {r, c + 1, node.key, node.count + 1};
                q.push(next);
            }
        }
        if (r > 0 && visited[r - 1][c] == 0) {
            if (maze[r - 1][c] == '*' && maze[r - 2][c] == '.' &&
                visited[r - 2][c] == 0 && node.key == 1) {
                Walk next = {r - 2, c, node.key - 1, node.count + 2};
                q.push(next);
            } else {
                Walk next = {r - 1, c, node.key, node.count + 1};
                q.push(next);
            }
        }
        if (c > 0 && visited[r][c - 1] == 0) {
            if (maze[r][c - 1] == '*' && maze[r][c - 2] == '.' &&
                visited[r][c - 2] == 0 && node.key == 1) {
                Walk next = {r, c - 2, node.key - 1, node.count + 2};
                q.push(next);
            } else {
                Walk next = {r, c - 1, node.key, node.count + 1};
                q.push(next);
            }
        }
    }

    cout << -1;
    // for (auto x : visited) {
    //     for (auto y : x) {
    //         cout << y;
    //     }
    //     cout << "\n";
    // }
    return 0;
}