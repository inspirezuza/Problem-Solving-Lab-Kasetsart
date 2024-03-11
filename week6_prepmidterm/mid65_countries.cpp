#include <bits/stdc++.h>

using namespace std;

void dfs(int current,
         int x,
         int y,
         vector<vector<int>> maze,
         vector<vector<int>> &visited,
         set<int> &connect) {

    if (x >= maze.size() || x < 0 || y >= maze[0].size() || y < 0) {
        return;
    }
    if (current != maze[x][y]) {
        connect.insert(maze[x][y]);
        return;
    }
    if (visited[x][y]) {
        return;
    }
    // cout << x << " " << y << "\n";
    visited[x][y] = 1;
    dfs(current, x + 1, y, maze, visited, connect);
    dfs(current, x, y + 1, maze, visited, connect);
    dfs(current, x - 1, y, maze, visited, connect);
    dfs(current, x, y - 1, maze, visited, connect);
}

int main() {
    int r, c, a, b, xx, yy;
    cin >> r >> c >> a >> b >> xx >> yy;
    vector<vector<int>> maze;
    vector<vector<int>> visited(r, vector<int>(c, 0));
    int maxcountry = 0;
    for (int i = 0; i < r; i++) {
        vector<int> temp;

        for (int j = 0; j < c; j++) {
            int block;
            cin >> block;
            maxcountry = max(maxcountry, block);
            temp.push_back(block);
        }
        maze.push_back(temp);
    }
    set<int> connect;
    vector<vector<int>> graph(maxcountry + 1);
    vector<int> visited_graph(maxcountry + 1, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j]) {
                // cout << maze.size() << maze[0].size();
                // cout << i << " " << j << "\n";
                connect.clear();
                dfs(maze[i][j], i, j, maze, visited, connect);
                // cout << maze[i][j] << ": ";
                for (auto x : connect) {

                    graph[maze[i][j]].push_back(x);
                }
                // cout << "\n";
            }
        }
    }
    // for (auto x : graph) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    queue<pair<int, int>> q;
    q.push({maze[a - 1][b - 1], 0});
    visited_graph[maze[a - 1][b - 1]] = 1;
    while (!q.empty()) {
        pair<int, int> qfront = q.front();
        int node = qfront.first;
        int dist = qfront.second;
        // cout << "cur" << node << "\n";
        if (node == maze[xx - 1][yy - 1]) {
            cout << dist;
            return 0;
        }
        q.pop();
        for (auto x : graph[node]) {
            if (!visited_graph[x]) {
                visited_graph[x] = 1;
                q.push({x, dist + 1});
            }
        }
    }
    return 0;
}