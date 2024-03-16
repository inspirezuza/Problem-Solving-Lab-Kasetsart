#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heights;
    vector<int> scores;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        heights.push_back(a);
        scores.push_back(b);
    }

    int ans = -1;
    for (int i = n - 1; i >= 0; i--) {
        int opt = scores[i];
        for (int j = i + 1; j < n; j++) {
            if (heights[i] - heights[j] <= k && heights[i] - heights[j] > -1) {
                if (scores[i] + scores[j] > opt) {
                    // cout << "new " << i << " " << j << " " << scores[i] << "
                    // "
                    //      << scores[j] << "\n";
                }
                opt = max(opt, scores[i] + scores[j]);
            }
        }
        scores[i] = opt;
        // if (scores[i] > ans) {
        //     cout << i << " " << scores[i] << "\n";
        // }
        ans = max(ans, scores[i]);
    }
    cout << ans;
    return 0;
}