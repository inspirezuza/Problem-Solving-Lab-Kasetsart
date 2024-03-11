#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int result = 0;
    int j = 0;
    for (int i = 0; i < T.length(); i++) {
        if (T[i] == S[j]) {
            j++;
            if (j >= S.length()) {
                result++;
                j = 0;
            }
        }
    }
    cout << result;
}