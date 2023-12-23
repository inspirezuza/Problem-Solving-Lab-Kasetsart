#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, action, index;
    cin >> n;
    unordered_map<int, tuple<int, int, int>>
        um;                                    // {index, {likes, time, index}}
    priority_queue<tuple<int, int, int>> pq;   // {likes, time, index}
    for (int i = 0; i < n; i++) {
        cin >> action >> index;
        if (action == 1) {
            if (um.find(index) != um.end()) {
                get<0>(um[index])++;
                get<1>(um[index]) = i;
            } else {
                um[index] = {1, i, index};
            }
            pq.push(um[index]);
        } else if (action == 0 && um.find(index) != um.end() &&
                   get<0>(um[index]) > 0) {
            get<0>(um[index])--;
            get<1>(um[index]) = i;
            pq.push(um[index]);
        }

        while (!pq.empty() &&
               (um.find(get<2>(pq.top())) == um.end() ||
                get<0>(um[get<2>(pq.top())]) != get<0>(pq.top()))) {
            pq.pop();
        }

        if (!pq.empty()) {
            cout << get<2>(pq.top()) << "\n";
        }
    }

    return 0;
}