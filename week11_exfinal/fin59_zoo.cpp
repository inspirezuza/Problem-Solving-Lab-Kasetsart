#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c, b, t;
    cin >> r >> c >> b >> t;
    vector<vector<int>> duck(r, vector<int>(c, 0));
    vector<bool> sumrow(r, false);
    int count = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            duck[i][j] = a;
            if (a) {
                sumrow[i] = true;
            }
        }
        if (!sumrow[i]) {
            count--;
        }
    }
    b = b / t;
    int bucket = b;
    int hole;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            hole = duck[i][j];
            while (hole > 0) {
                if (bucket == 0) {
                    count++;
                    bucket = b;
                }
                if (hole > bucket) {
                    hole -= bucket;
                    bucket = 0;
                } else {
                    bucket -= hole;
                    hole = 0;
                }
                // cout << "cur " << hole << " " << bucket << " " << count <<
                // "\n";
            }
        }
        count++;
        bucket = b;
        // cout << "thiaas "
        //      << " " << count << "\n";
    }
    cout << count - 1;
    return 0;
}