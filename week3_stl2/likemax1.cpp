#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num, status;
    cin >> n;
    int max_val = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (um.find(num) == um.end()) {
            um[num] = 1;
        } else {
            um[num]++;
        }
        if (um[num] >= max_val) {
            max_val = um[num];
            status = num;
        }
        cout << status << "\n";
    }

    return 0;
}