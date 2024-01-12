#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    int count = 0;
    int mintime = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second >= mintime) {
            mintime = v[i].first;
            count++;
        }
    }
    cout << count;

    return 0;
}