#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> jobs;
    while (n--) {
        int d, c;
        cin >> d >> c;
        jobs.push_back(make_pair(d, c));
    }
    sort(jobs.begin(), jobs.end());
    int result = 0;
    int workday = 0;
    for (auto x : jobs) {
        workday += x.second;
        if ((workday - x.first - 10) > 0) {
            result = max(result, (workday - x.first - 10) * 1000);
        }
    }
    cout << result;
    return 0;
}