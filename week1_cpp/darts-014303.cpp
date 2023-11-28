// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    float n,a,b;
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a >> b;   
        for(int j=1;j<=5;j++){
            if (sqrt(a*a + b*b) <= j*2){
                sum+= 5-j+1;
                break;
            }
            
        }
        
    }
    cout << sum;
    return 0;
}