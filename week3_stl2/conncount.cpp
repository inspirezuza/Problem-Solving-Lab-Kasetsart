#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, rankparent;
int n, m, a, b;

int find(int a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    n--;
    if (rankparent[a] > rankparent[b]) {
        parent[b] = a;
        rankparent[a] += rankparent[b];
    } else {
        parent[a] = b;
        rankparent[b] += rankparent[a];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++) {
        parent.push_back(i);
        rankparent.push_back(1);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unite(a, b);
    }
    cout << n;
    return 0;
}