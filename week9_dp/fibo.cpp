#include <iostream>
using namespace std;

const int MOD = 199933;

long long fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Invalid input\n";
        return 1;
    }

    cout << fib(n) << endl;
    return 0;
}
