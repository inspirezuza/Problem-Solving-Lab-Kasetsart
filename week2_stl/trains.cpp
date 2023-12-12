#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, vector<int>> platform;

    for (int i = 0; i < n; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'N') {
            platform[b].push_back(a);
        } else {
            platform[b].insert(platform[b].end(), platform[a].begin(),
                               platform[a].end());
            platform.erase(a);
        }
    }
    for (auto x : platform) {
        for (auto y : x.second) {
            cout << y << "\n";
        }
    }
    return 0;
}