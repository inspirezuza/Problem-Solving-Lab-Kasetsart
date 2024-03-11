#include <bits/stdc++.h>

using namespace std;

int main() {

    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        int a;
        int count[105] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a;
            count[a]++;
        }
        for (int i = 1; i <= 100; i++) {
            for (int j = 0; j < count[i]; j++) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}