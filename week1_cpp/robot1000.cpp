#include <bits/stdc++.h>

using namespace std;

int main() {
    string walk;
    int x = 0;
    int y = 0;
    cin >> walk;
    for (int i = 0; i < walk.length(); i++) {
        if (walk[i] == 'N')
            y++;
        else if (walk[i] == 'S')
            y--;
        else if (walk[i] == 'E')
            x++;
        else if (walk[i] == 'W')
            x--;
        else if (walk[i] == 'Z') {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y;
}