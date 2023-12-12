#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> v;

    for (int i = 0; i < n; i++) {
        string op;
        int num;
        cin >> op;
        if (op == "ri") {
            cin >> num;
            v.push_back(num);
        } else if (op == "li") {
            cin >> num;
            v.push_front(num);
        } else if (op == "rr") {
            v.push_front(v.back());
            v.pop_back();
        } else if (op == "lr") {
            v.push_back(v.front());
            v.pop_front();
        }
    }
    for (auto it = begin(v); it != end(v); it++) {
        cout << *it << "\n";
    }

    return 0;
}