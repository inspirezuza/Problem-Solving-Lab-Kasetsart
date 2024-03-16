#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> rating(n + 1);
    vector<pair<int, int>> counts(n + 1, pair<int, int>({0, 0}));

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (i - counts[a].second > 6) {
            rating[a] = max(rating[a], counts[a].first);
            counts[a].first = 0;
        }
        counts[a].first++;
        counts[a].second = i;
    }
    for (int i = 1; i < n + 1; i++) {
        rating[i] = max(rating[i], counts[i].first);
        // cout << rating[i] << " ";
    }
    // cout << "\n";
    int ans = 0;
    int index;
    for (int i = 1; i < n + 1; i++) {
        if (rating[i] > ans) {
            ans = rating[i];
            index = i;
        }
    }
    cout << index << " " << ans;
    return 0;
}