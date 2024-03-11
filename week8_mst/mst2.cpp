#include <bits/stdc++.h>

using namespace std;

typedef struct Edge {
    int src, dest, weight;
} Edge;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

struct CompareEdge {
    bool operator()(Edge &a, Edge &b) { return a.weight > b.weight; }
};

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

int KruskalMST(priority_queue<Edge, vector<Edge>, CompareEdge> pq,
               vector<int> &parent,
               vector<int> &rank) {
    int mst_wt = 0;
    while (!pq.empty()) {
        Edge top = pq.top();
        pq.pop();
        int x = find(top.src, parent);
        int y = find(top.dest, parent);
        if (x != y) {
            mst_wt += top.weight;
            unite(x, y, parent, rank);
        }
    }
    return mst_wt;
}

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        Edge temp = {a, b, w};
        pq.push(temp);
    }

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int mst_wt = KruskalMST(pq, parent, rank);
    cout << mst_wt;

    return 0;
}
