#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> woods;
    vector<int> total_woods;
    set<int> answer;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        total += a;
        woods.push_back(a);
        total_woods.push_back(total);
    }
    int l, r, cur;
    for (int i = 0; i < n; i++) {
        // cout << i << "\n";
        l = 0;
        r = i + 1;
        cur = total_woods[i];
        answer.insert(cur);
        // cout << cur << " " << l << " " << r << "\n";

        for (int j = i; j < n - 1; j++) {
            cur -= woods[l];
            cur += woods[r];
            answer.insert(cur);
            // cout << cur << " " << l << " " << r << "\n";
            l++;
            r++;
        }
    }

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (answer.find(a) != answer.end()) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    return 0;
}