#include <bits/stdc++.h>

using namespace std;

typedef struct Point {
    float x;
    float y;
    float layer;
} Point;

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {

    int n, r;
    float a, b;
    cin >> n >> r;

    list<Point> l;
    queue<Point> q;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        Point temp;
        temp.x = a;
        temp.y = b;
        temp.layer = -1;
        l.push_back(temp);
    }

    Point temp;
    temp.x = 100;
    temp.y = 100;
    temp.layer = -1;
    l.push_back(temp);

    temp.x = 0;
    temp.y = 0;
    temp.layer = 0;
    q.push(temp);

    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (auto it = l.begin(); it != l.end();) {
            if (distance(p.x, p.y, it->x, it->y) <= r) {
                if (it->x == 100 && it->y == 100) {
                    cout << p.layer + 1;
                    return 0;
                }
                it->layer = p.layer + 1;

                q.push(*it);
                l.erase(it++);

            } else {
                ++it;
            }
        }
    }
    cout << -1;

    return 0;
}
