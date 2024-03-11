#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> houses;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        houses.push_back(a);
    }
    sort(houses.begin(), houses.end());
    int maxdist = 0;
    for (int i = 0; i < n - k - l; i++) {
        maxdist = max(maxdist, houses[i + k + l] - houses[i]);
    }
    cout << maxdist;
    return 0;
}