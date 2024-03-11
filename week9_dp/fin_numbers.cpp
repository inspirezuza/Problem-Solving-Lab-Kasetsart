#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int stairs[100001];
    bool requirement[100001];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        stairs[i] = a;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        requirement[i] = a;
    }
    int result = 0;
    int step = 0;
    while (step < n) {
        int worstStep = -1;
        for (int i = step; i < step + 4; i++) {
            if (requirement[i]) {
                step = i;
                break;
            } else if (stairs[i] >= 0) {
                step = i;
                break;
            } else {
                worstStep = max(worstStep, stairs[i]);
            }
        }
    }
    return 0;
}