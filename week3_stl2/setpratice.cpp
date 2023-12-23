#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, num;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    cout << "\n";
    for (int i = 0; i < m; i++) {
        cin >> num;
        auto it = s.lower_bound(num);
        if (it == s.end()) {
            cout << *prev(it) << "\n";
        } else {
            if (abs(*it - num) < abs(*prev(it) - num) || it == s.begin()) {
                cout << *it << "\n";
            } else {
                cout << *prev(it) << "\n";
            }
        }
    }

    return 0;
}