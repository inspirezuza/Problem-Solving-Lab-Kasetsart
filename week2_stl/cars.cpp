#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, v;
    int count = 0;
    cin >> n;
    vector<int> cars;

    for (int i = 0; i < n; i++) {
        cin >> p >> v;
        cars.push_back(v);
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }

    int max_val = cars[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (max_val > cars[i]) {
            count++;
            continue;
        }
        max_val = max(max_val, cars[i]);
    }
    cout << count;

    return 0;
}