#include <bits/stdc++.h>

using namespace std;

int main() {
    long m, event, a, b;
    cin >> m;
    unordered_map<int, long> um;
    while (m--) {
        cin >> event;
        if (event == 1) {
            cin >> a >> b;
            if (um.find(a) == um.end()) {
                um[a] = b;
            } else {
                um[a] += b;
            }
        } else if (event == 2) {
            cin >> a;
            if (um.find(a) == um.end()) {
                cout << 0 << "\n";
            } else {
                cout << um[a] << "\n";
            }
        } else {
            cin >> a >> b;
            if (um.find(a) == um.end()) {
                cout << 0 << "\n";
            } else if (um[a] < b) {
                cout << um[a] << "\n";
                um[a] = 0;
            } else {
                um[a] -= b;
                cout << b << "\n";
            }
        }
    }

    return 0;
}