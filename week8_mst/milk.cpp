#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &parent) {
    if (parent[x] != x)
        parent[x] = find(parent[x], parent);
    return parent[x];
}

void unite(int x, int y, vector<int> &parent, vector<int> &rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < q; i++) {
        char question;
        cin >> question;
        if (question == 'q') {
            int a, b;
            cin >> a >> b;
            if (find(a, parent) == find(b, parent)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (question == 'c') {
            int a, b;
            cin >> a >> b;
            unite(a, b, parent, rank);
        }
    }
    return 0;
}
