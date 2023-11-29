// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    int n;
    int sum = 0;
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
            
        cin >> a;
        if ( a  > 0){
            sum += a;  
        }
    }
    cout << sum;
    return 0;
}