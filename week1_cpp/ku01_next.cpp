// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    int maxcount = 0;
    int send[100002] = {};
    int check[100002] = {};
    for(int i=1;i<n+1;i++){
        cin >> send[i];
        
    }
    
    for(int i=1;i<n+1;i++){
        if(check[i]){
            continue;
        }
        int count = 1;
        int hold = send[i];
        while(hold != i){
            hold = send[hold];
            check[hold] = 1;
            count++;
            
        }
        maxcount = max(count,maxcount);
    }
    cout << maxcount;
    return 0;
}