#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> land;
vector<vector<int>> visited;

int qualityMedium = 0;
int qualityBest = 0;
int countland = 0;
bool forest = 0;
bool mineral = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= land.size() || y < 0 || y >= land[0].size()) {
        return;
    }
    if (visited[x][y] == 1 || land[x][y] == '#') {
        return;
    }
    if (land[x][y] == '$') {
        mineral = 1;
    }
    if (land[x][y] == '*') {
        forest = 1;
    }
    visited[x][y] = 1;
    countland++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<char> row;
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            row.push_back(c);
            temp.push_back(0);
        }
        land.push_back(row);
        visited.push_back(temp);
    }

    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (visited[i][j] == 0 && land[i][j] != '#') {
                dfs(i, j);
                if (forest && mineral) {
                    qualityBest += countland;
                } else if (forest || mineral) {
                    qualityMedium += countland;
                }
                countland = 0;
                forest = 0;
                mineral = 0;
            }
        }
    }

    cout << qualityBest << " " << qualityMedium;

    return 0;
}