#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> v;

    for (int i = 0; i < n; i++) {
        int num;
        char op;
        cin >> op >> num;
        if (op == 'A') {
            v.push_back(num);
        } else if (op == 'I') {
            v.push_front(num);
        } else {
            if (num > v.size())
                continue;
            v.erase(next(begin(v), num - 1));
        }
    }
    for (auto it = begin(v); it != end(v); it++) {
        cout << *it << "\n";
    }

    return 0;
}