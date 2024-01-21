#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> orders;
    vector<int> items;
    for (int i = 0; i < k; i++) {
        int c, p, w;
        cin >> c >> p >> w;
        orders.push_back({c, p, w});
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        items.push_back(a);
    }
    int result = INT_MAX;
    for (int i = 0; i < k; i++) {   // orders
        int total_weight = 0;
        int count = 0;
        int possible = 1;
        for (int j = 0; j < n; j++) {   // items
            if (orders[i][2] < items[j]) {
                possible = 0;
                break;
            }
            total_weight += items[j];
            if (orders[i][2] < total_weight) {
                j--;
                total_weight = 0;
                count++;
            }
        }
        count++;
        if (possible) {
            result = min(result, orders[i][0] + orders[i][1] * count);
            // cout << orders[i][0] << " " << orders[i][1] << " " << count <<
            // "\n";
        }
    }
    cout << result;
    return 0;
}