#include <bits/stdc++.h>

using namespace std;

int dist(char a, char b) { return min(abs(a - b), abs(abs(a - b) - 26)); }

void solve(string s) {
    // cout << dist('Y', 'A') << "\n";
    if (s.size() == 0) {
        cout << 0;
        return;
    }
    if (s.size() == 1) {
        cout << dist('A', s[0]);
        return;
    }
    vector<vector<int>> dp;
    dp.push_back({dist('A', s[0]), s[0], 'A'});
    // for (auto y : dp) {
    //     printf("%d %c %c \n", y[0], y[1], y[2]);
    // }
    int curdist, pass;
    for (int i = 1; i < s.size(); i++) {
        vector<vector<int>> temp;
        for (auto x : dp) {
            pass = 1;
            curdist = dist(x[1], s[i]) + x[0];
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j][2] == x[2]) {
                    // cout << temp[j][0] << " " << curdist << "\n";
                    temp[j][0] = min(temp[j][0], curdist);
                    // cout << "now " << temp[j][0] << "\n";
                    pass = 0;
                }
            }
            if (pass) {
                temp.push_back({curdist, s[i], x[2]});
            }

            pass = 1;
            curdist = dist(x[2], s[i]) + x[0];
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j][2] == x[1]) {
                    // cout << temp[j][0] << " " << curdist << "\n";
                    temp[j][0] = min(temp[j][0], curdist);
                    // cout << "now " << temp[j][0] << "\n";
                    pass = 0;
                }
            }
            if (pass) {
                temp.push_back({curdist, s[i], x[1]});
            }
        }
        dp = temp;
        // for (auto y : dp) {
        //     printf("%d %c %c \n", y[0], y[1], y[2]);
        // }
        // cout << "\n";
    }
    int ans = INT_MAX;
    for (auto x : dp) {
        ans = min(ans, x[0]);
    }
    cout << ans << "\n";
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        solve(s);
    }
}