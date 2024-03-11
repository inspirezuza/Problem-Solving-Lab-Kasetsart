#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

void program() {
    int m;
    cin >> m;
    vector<pair<int, int>> fences;
    vector<pair<int, int>> result;
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        if (b < 0) {
            continue;
        }
        if (a < 0) {
            a = 0;
        }
        fences.push_back({a, b});
    }
    sort(fences.begin(), fences.end(), cmp);
    // cout << "sort";
    // for (auto x : fences) {
    //     cout << x.first << " " << x.second << "\n";
    // }
    if (fences[0].first != 0) {
        cout << 0 << "\n";
        return;
    }
    int count = 1;

    result.push_back({fences[0].first, fences[0].second});
    int maxfence = fences[0].second;
    for (auto it = next(fences.begin()); it != fences.end(); it++) {
        if ((*it).first > maxfence) {
            cout << 0 << "\n";
            return;
        }
        if ((*it).second > maxfence) {
            maxfence = (*it).second;
            count++;
            result.push_back({(*it).first, (*it).second});
        }
    }
    cout << count << "\n";
    for (auto x : result) {
        cout << x.first << " " << x.second << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    char blank;
    for (int i = 0; i < n; i++) {
        string blank;
        getline(cin, blank);
        program();
        cout << "\n";
    }
    return 0;
}