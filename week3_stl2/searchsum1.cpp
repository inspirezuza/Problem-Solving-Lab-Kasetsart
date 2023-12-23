#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, num;
    cin >> n >> k;
    int arr[100000];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    for (int i = 0; i < k; i++) {
        cin >> num;
        int index = upper_bound(arr, arr + n, num) - arr;
        printf("%d\n", index);
    }

    return 0;
}