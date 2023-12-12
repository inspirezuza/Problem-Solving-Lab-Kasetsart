#include <bits/stdc++.h>

using namespace std;

void concatresult(list<string> &result, string text, int state) {
    if (state == 0) {
        result.push_back(text);
    } else if (state == 1) {
        result.push_front(text);
    } else {
        result.push_back(text);
    }
}

int main() {
    string frase;
    list<string> result;
    string text;
    int state = 0;   // 0 normal 1 home 2 end
    while (getline(cin, frase)) {

        for (int i = 0; i < frase.size(); i++) {
            if (frase[i] == '[') {
                concatresult(result, text, state);
                state = 1;
                text.clear();
            } else if (frase[i] == ']') {
                concatresult(result, text, state);
                state = 2;
                text.clear();
            } else {
                text += frase[i];
            }
        }
        concatresult(result, text, state);
        for (auto it = result.begin(); it != result.end(); it++) {
            cout << *it;
        }
        cout << endl;
        frase.clear();
        result.clear();
        text.clear();
        state = 0;
    }

    return 0;
}