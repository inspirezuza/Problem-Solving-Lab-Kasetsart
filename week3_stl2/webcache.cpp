#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, num;
    cin >> n >> m;
    int result = 0;
    queue<int> q;
    unordered_set<int> us;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if (us.find(num) == us.end()) {
            q.push(num);
            us.insert(num);
            result++;
            if (q.size() > n) {
                us.erase(q.front());
                q.pop();
            }
        }
    }
    cout << result;
    return 0;
}