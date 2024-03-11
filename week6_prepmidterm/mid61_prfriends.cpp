#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int l, int r) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[r + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= r; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= r; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    vector<int> primes;
    for (int p = l; p <= r; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }
    int count = 0;
    for (int i = 1; i < primes.size(); i++) {
        if (primes[i] - primes[i - 1] == 2) {
            count++;
        }
    }
    cout << count;
}

// Driver Code
int main() {
    int l, r;
    cin >> l >> r;
    SieveOfEratosthenes(l, r);
    return 0;
}