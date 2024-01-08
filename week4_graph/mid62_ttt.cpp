#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
  public:
    int V;
    vector<vector<int>> adj;

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite() {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(i, color)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartiteUtil(int src, vector<int> &color) {
        color[src] = 1;
        stack<int> s;
        s.push(src);

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    s.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }

        return true;
    }

    void removeEdgeToMakeBipartite() {
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                // Try removing edge (u, v) and check if the graph becomes
                // bipartite
                int temp = adj[u].back();
                adj[u].pop_back();
                adj[v].pop_back();

                if (isBipartite()) {
                    cout << "Edge (" << u << ", " << v
                         << ") removed to make the graph bipartite." << endl;
                    return;
                }

                // Restore the edge if removing it does not make the graph
                // bipartite
                adj[u].push_back(temp);
                adj[v].push_back(u);
            }
        }

        cout << "No edge can be removed to make the graph bipartite." << endl;
    }
};

int main() {
    // Example usage
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.isBipartite()) {
        cout << "The graph is already bipartite." << endl;
    } else {
        g.removeEdgeToMakeBipartite();
    }

    return 0;
}
