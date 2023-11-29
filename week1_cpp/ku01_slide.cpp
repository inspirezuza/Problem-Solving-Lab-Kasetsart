#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int penguin[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> penguin[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (penguin[i] < penguin[j]) {
                count++;
            }
        }
    }
    cout << count;
}