#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    unordered_map<int, list<int> *> um;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        if (um.find(b) == um.end()) {
            um[b] = new list<int>({b});
        }

        auto it = find(um[b]->begin(), um[b]->end(), b);
        if (um.find(a) == um.end()) {
            um[b]->emplace(next(it), a);
            um[a] = um[b];
        } else {
            list<int> *temp = um[a];
            for (auto x : *um[a]) {
                um[x] = um[b];
            }

            um[b]->splice(next(it), *temp);
        }
        // for (auto x : um) {
        //     cout << x.first << "-> ";
        //     for (auto y : *x.second) {
        //         cout << y << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    for (auto x : *um[1]) {
        cout << x << " ";
    }
}