#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> ships;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ships.push_back(a);
    }
    ships.sort();
    vector<int> passengers;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        passengers.push_back(a);
    }
    int count = 0;
    int j = 0;
    bool possible = true;
    for (int i = 0; i < m; i++) {
        auto low = lower_bound(ships.begin(), ships.end(), passengers[i]);
        if (low == ships.end()) {
            break;
        } else {
            // cout << *low << " ";
            ships.erase(low);
            count++;
        }
    }
    cout << count;
    return 0;
}