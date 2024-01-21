#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> min_height(n + 1);
    min_height[0] = INT_MAX;
    int temp = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        temp = min(temp, height);
        min_height[i] = temp;
    }

    vector<int> rmin_height;
    for (auto it = min_height.rbegin(); it != min_height.rend(); ++it) {
        rmin_height.push_back(*it);
    }
    int value;
    for (int i = 0; i < q; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            cin >> value;
            cout << min_height[value];
        } else if (command == 2) {
            cin >> value;
            if (value > min_height[0]) {
                cout << 0;
                continue;
            }
            auto low =
                lower_bound(rmin_height.begin(), rmin_height.end(), value);
            cout << n - distance(rmin_height.begin(), low);
        }
        cout << "\n";
    }

    return 0;
}