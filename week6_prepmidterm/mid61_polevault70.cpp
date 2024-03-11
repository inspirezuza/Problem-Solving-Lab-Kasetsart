#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> woods;
    set<int> answer;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        woods.push_back(a);
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int total = 0;
            for (int k = j; k < j + i; k++) {
                total += woods[k];
            }
            answer.insert(total);
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