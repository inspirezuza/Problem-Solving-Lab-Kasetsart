#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Adjust the size of the vectors to accommodate node numbers starting from
    // 1
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    // cout << "Enter the edges:\n";
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     graph[u].push_back(v);
    //     inDegree[v]++;
    // }

    // Print out all values in graph
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
