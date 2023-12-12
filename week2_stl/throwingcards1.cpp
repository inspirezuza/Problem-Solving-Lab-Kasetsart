#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    queue<int> deck;

    while (1) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 1; i <= n; i++) {
            deck.push(i);
        }

        cout << "Discarded cards:";
        while (deck.size() > 1) {
            cout << " " << deck.front();
            deck.pop();
            x = deck.front();
            deck.pop();
            if (!deck.empty())
                cout << ",";
            deck.push(x);
        }
        cout << endl;

        cout << "Remaining card: " << deck.front() << endl;
        deck.pop();
    }

    return 0;
}