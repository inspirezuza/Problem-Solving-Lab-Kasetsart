#include <iostream>
#include <vector>

using namespace std;

int maxCountSubarray(const vector<int> &arr, int money) {
    int n = arr.size();
    int maxCount = 0;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        currentSum += arr[end];

        while (currentSum > money && start <= end) {
            currentSum -= arr[start];
            start++;
        }

        maxCount = max(maxCount, end - start + 1);
    }

    return maxCount;
}

int main() {
    int n, k, book, money;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> book;
        arr.push_back(book);
    }
    for (int i = 0; i < k; i++) {
        cin >> money;
        cout << maxCountSubarray(arr, money) << "\n";
    }

    return 0;
}
