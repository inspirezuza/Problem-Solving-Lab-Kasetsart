#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int oldh, newh;
    cin >> oldh;
    for (int i = 1; i < n; i++) {
        cin >> newh;
        arr[i] += abs(oldh - newh);
        oldh = newh;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}