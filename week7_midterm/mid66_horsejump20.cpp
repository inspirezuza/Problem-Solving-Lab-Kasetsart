#include <bits/stdc++.h>

using namespace std;

bool checkMazeValid(int x, int y, vector<vector<char>> maze) {
    if (x >= maze.size() || x < 0 || y >= maze[0].size() || y < 0) {
        return false;
    }
    if (maze[x][y] == '#') {
        return false;
    }
    // cout << x << " " << y << "\n";
    return true;
}

typedef struct Node {
    int node;
    int dist;
    bool jump;
} Node;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n * n + 1);
    vector<int> visited(n * n + 1, 0);
    vector<vector<char>> maze;
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            temp.push_back(c);
        }
        maze.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == '#') {
                continue;
            }
            // cout << "iam " << i << " " << j << "\n";
            if (checkMazeValid(i + 1, j, maze)) {
                graph[i * n + j].push_back((i + 1) * n + j);
                // graph[(i + 1) * n + j].push_back(i * n + j);
            }
            if (checkMazeValid(i, j + 1, maze)) {
                graph[i * n + j].push_back((i) *n + j + 1);
                // graph[(i) *n + j + 1].push_back(i * n + j);
            }
            if (checkMazeValid(i - 1, j, maze)) {
                graph[i * n + j].push_back((i - 1) * n + j);
                // graph[(i - 1) * n + j].push_back(i * n + j);
            }
            if (checkMazeValid(i, j - 1, maze)) {
                graph[i * n + j].push_back(i * n + j - 1);
                // graph[i * n + j - 1].push_back(i * n + j);
            }

            // horse
            if (checkMazeValid(i - 2, j - 1, maze)) {
                graph[i * n + j].push_back((i - 2) * n + j - 1);
            }
            if (checkMazeValid(i - 2, j + 1, maze)) {
                graph[i * n + j].push_back((i - 2) * n + j + 1);
            }
            if (checkMazeValid(i - 1, j + 2, maze)) {
                graph[i * n + j].push_back((i - 1) * n + j + 2);
            }
            if (checkMazeValid(i + 1, j + 2, maze)) {
                graph[i * n + j].push_back((i + 1) * n + j + 2);
            }
            if (checkMazeValid(i + 2, j + 1, maze)) {
                graph[i * n + j].push_back((i + 2) * n + j + 1);
            }
            if (checkMazeValid(i + 2, j - 1, maze)) {
                graph[i * n + j].push_back((i + 2) * n + j - 1);
            }
            if (checkMazeValid(i + 1, j - 2, maze)) {
                graph[i * n + j].push_back((i + 1) * n + j - 2);
            }
            if (checkMazeValid(i - 1, j - 2, maze)) {
                graph[i * n + j].push_back((i - 1) * n + j - 2);
            }
        }
    }
    // int i = 0;
    // for (auto x : graph) {
    //     cout << i << ": ";
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    //     i++;
    // }
    queue<Node> q;
    vector<int> check_visited(n * n + 1, 0);
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto qfront = q.front();
        int node = qfront.node;
        int dist = qfront.dist;
        bool jump = qfront.jump;
        if (node == n * n - 1) {
            cout << dist;
            return 0;
        }
        q.pop();
        // visited_graph[node] = 1;
        // cout << node << ": ";
        for (auto x : graph[node]) {
            if (!check_visited[x]) {
                q.push({x, dist + 1, jump});
            }
        }
    }

    return 0;
}