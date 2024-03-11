#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> patients(n + 1, 0);
    int total_patient = 0;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int a, b;
            cin >> a >> b;
            if (i + b <= n + 1) {
                patients[i + b] += a;
            }
            total_patient += a;
        }
        total_patient -= patients[i];
        cout << total_patient << "\n";
    }
    return 0;
}