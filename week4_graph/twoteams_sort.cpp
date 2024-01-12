#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> color(n + 1, -1);
    for (int i = 1; i < m + 1; i++) {
        cin >> a >> b;
        if (color[a] == -1 && color[b] == -1) {
            color[a] = 0;
            color[b] = 1;
        } else if (color[a] == color[b]) {
            cout << i - 1;
            break;
        } else {
            if (color[a] == -1) {
                color[a] = 1 - color[b];
            } else if (color[b] == -1) {
                color[b] = 1 - color[a];
            }
        }
    }

    return 0;
}