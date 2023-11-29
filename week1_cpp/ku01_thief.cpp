#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    int player = 0;
    int count = 0;
    cin >> n >> k >> t;
    if (t == 0) {
        cout << 0;
        return 0;
    }
    player += (player + k) % n;
    count++;
    while (player != 0) {
        if (player == t - 1) {
            count++;
            break;
        }
        player = (player + k) % n;
        count++;
    }
    cout << count;
}