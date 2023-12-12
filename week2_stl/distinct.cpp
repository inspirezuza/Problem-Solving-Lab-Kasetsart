#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int store[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }

    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += store[j];
            s.insert(sum);
        }
    }
    cout << s.size();

    return 0;
}