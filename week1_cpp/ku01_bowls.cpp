// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    int n;
    int maxval = 0;
    cin >> n;
    int plate;
    unordered_map<int, int> count;
    for (int i=0; i<n; i++){
        cin >> plate;
        count[plate]++;       
    }
    for (int i=0;i<301;i++){
        maxval = max(maxval,count[i]);
    }
    cout << maxval;
    return 0;
}