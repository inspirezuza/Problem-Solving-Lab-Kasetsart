#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> horizontal(500001, 0);
    map<int, int> answer;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = a; j >= 1; j--) {
            horizontal[j]++;
        }
        for (int j = a + 1; j <= a + 6; j++) {
            if (horizontal[j] == 0) {
                continue;
            }
            if (answer.find(horizontal[j]) == answer.end()) {
                answer[horizontal[j]] = 1;
            } else {
                answer[horizontal[j]] += 1;
            }
            horizontal[j] = 0;
        }

        // for (int i = 0; i < 5; i++) {
        //     cout << horizontal[i] << " ";
        // }
        // cout << "\n";
    }
    for (int j = 0; j <= 5; j++) {
        if (horizontal[j] == 0) {
            continue;
        }
        if (answer.find(horizontal[j]) == answer.end()) {
            answer[horizontal[j]] = 1;
        } else {
            answer[horizontal[j]] += 1;
        }
        horizontal[j] = 0;
    }
    cout << answer.size() << "\n";
    for (auto x : answer) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}