#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> houses;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        houses.push_back({a, b});
    }
    sort(houses.begin(), houses.end());
    int current_cover = 0;
    int result = 0;
    for (auto x : houses) {
        if (x.second > current_cover) {
            result++;
            current_cover = x.first + l;
        }
    }
    cout << result;
    return 0;
}