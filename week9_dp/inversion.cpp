#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    long long inversionCount = 0;

    int i = left;      // Index for left subarray
    int j = mid + 1;   // Index for right subarray
    int k = 0;         // Index for temp array

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversionCount += mid - i + 1;   // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; ++p) {
        arr[left + p] = temp[p];
    }

    return inversionCount;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inversionCount += mergeSort(arr, left, mid);
        inversionCount += mergeSort(arr, mid + 1, right);
        inversionCount += merge(arr, left, mid, right);
    }
    return inversionCount;
}

long long countInversions(vector<int> &arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    cout << countInversions(arr) << endl;
    return 0;
}
