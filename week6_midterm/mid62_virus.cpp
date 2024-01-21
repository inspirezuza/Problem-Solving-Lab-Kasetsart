#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> virus;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        virus.push_back(a);
    }
    int value;
    auto it = virus.begin();
    for (int i = 0; i < m; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            it = virus.begin();
        } else if (command == 2) {
            it = next(it);
            if (it == virus.end()) {
                it = virus.begin();
            }
        } else if (command == 3) {
            cin >> value;
            virus.insert(it, value);
        } else if (command == 4) {
            cin >> value;
            virus.insert(next(it), value);
        }
    }
    for (auto x : virus) {
        cout << x << "\n";
    }

    return 0;
}