#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int color;
    int subGraph;
} Node;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, Node> um;
    vector<vector<unordered_set<int>>> subGraphColor;
    int result = 0;
    int subGraph = 0;
    int end = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (end) {
            continue;
        }
        result++;

        if (um.find(a) == um.end() && um.find(b) == um.end()) {
            um[a] = {0, subGraph};
            um[b] = {1, subGraph};
            subGraphColor.push_back(vector<unordered_set<int>>(0));
            subGraphColor[subGraph].push_back(unordered_set<int>(0));
            subGraphColor[subGraph].push_back(unordered_set<int>(0));
            subGraphColor[subGraph][0].insert(a);
            subGraphColor[subGraph][1].insert(b);
            subGraph++;
        } else if (um.find(a) == um.end() && um.find(b) != um.end()) {
            um[a] = {1 - um[b].color, um[b].subGraph};
            subGraphColor[um[b].subGraph][um[a].color].insert(a);
        } else if (um.find(b) == um.end() && um.find(a) != um.end()) {
            um[b] = {1 - um[a].color, um[a].subGraph};
            subGraphColor[um[a].subGraph][um[b].color].insert(b);
        } else if (um[a].subGraph == um[b].subGraph) {
            if (um[a].color == um[b].color) {
                cout << a << b << "\n";
                for (auto x : um) {
                    cout << x.first << ": ";
                    cout << x.second.color << " " << x.second.subGraph << "\n";
                }
                cout << "\n";

                end = 1;
                result--;
            } else {
                continue;
            }
        } else if (um[a].subGraph != um[b].subGraph) {
            cout << "hello";
            if (subGraphColor[um[a].subGraph][0].size() +
                    subGraphColor[um[a].subGraph][1].size() >
                subGraphColor[um[b].subGraph][0].size() +
                    subGraphColor[um[b].subGraph][1].size()) {
                if (um[a].color != um[b].color) {
                    subGraphColor[um[a].subGraph][um[a].color].insert(
                        subGraphColor[um[b].subGraph][um[b].color].begin(),
                        subGraphColor[um[b].subGraph][um[b].color].end());
                } else {
                    subGraphColor[um[a].subGraph][1 - um[a].color].insert(
                        subGraphColor[um[b].subGraph][um[b].color].begin(),
                        subGraphColor[um[b].subGraph][um[b].color].end());
                }
            } else {
                if (um[a].color != um[b].color) {
                    subGraphColor[um[b].subGraph][um[b].color].insert(
                        subGraphColor[um[a].subGraph][um[a].color].begin(),
                        subGraphColor[um[a].subGraph][um[a].color].end());
                } else {
                    subGraphColor[um[b].subGraph][1 - um[b].color].insert(
                        subGraphColor[um[a].subGraph][um[a].color].begin(),
                        subGraphColor[um[a].subGraph][um[a].color].end());
                }
            }
        }
        for (auto x : um) {
            cout << x.first << ": ";
            cout << x.second.color << " " << x.second.subGraph << "\n";
        }
        cout << "\n";
    }
    cout << result;
    return 0;
}
