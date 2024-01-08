#include <bits/stdc++.h>

using namespace std;

int dfsMaze(vector<vector<char>> &newmaze,
            int x,
            int y,
            vector<vector<int>> &visited) {
    if (newmaze[x][y] == '#') {
        return 0;
    }
    if (x == newmaze.size() - 1) {
        return 1;
    }
    visited[x][y] = 1;
    // cout << x << " " << y << "\n";
    if (x > 0 && visited[x - 1][y] == 0) {
        if (dfsMaze(newmaze, x - 1, y, visited)) {
            return 1;
        }
    }
    if (x < newmaze.size() - 1 && visited[x + 1][y] == 0) {
        if (dfsMaze(newmaze, x + 1, y, visited)) {
            return 1;
        }
    }
    if (y > 0 && visited[x][y - 1] == 0) {
        if (dfsMaze(newmaze, x, y - 1, visited)) {
            return 1;
        }
    }
    if (y < newmaze.size() - 1 && visited[x][y + 1] == 0) {
        if (dfsMaze(newmaze, x, y + 1, visited)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze;
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            temp.push_back(c);
        }
        maze.push_back(temp);
    }

    // reduce maze to 1*1
    vector<vector<char>> newmaze;
    for (int i = 0; i < n - 1; i++) {
        vector<char> temp;
        for (int j = 0; j < m - 1; j++) {
            if (maze[i][j] == '.' && maze[i + 1][j] == '.' &&
                maze[i][j + 1] == '.' && maze[i + 1][j + 1] == '.') {
                temp.push_back('.');

            } else {
                temp.push_back('#');
            }
        }
        newmaze.push_back(temp);
    }

    // Print out all values in new maze
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < m - 1; j++) {
    //         cout << newmaze[i][j];
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> visited(n - 1, vector<int>(m - 1, 0));
    for (int i = 0; i < m - 1; i++) {
        if (dfsMaze(newmaze, 0, i, visited)) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";

    return 0;
}