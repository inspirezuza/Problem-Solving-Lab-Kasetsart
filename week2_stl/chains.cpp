// มีวิธีที่ดีกว่าโค้ดนี้ idea จาก run cpe36
// struct เก็บชี้ 2 ตัว
// การเดิน จะมีค่า iter กับ backward ไว้
// ถ้าเดินไปด้านหน้า iter จะเดินไปทางตรงกัน backward
// ถ้าเดินไปด้านหลัง backward จะเดินไปทางตรงกัน iter
// โดยรวม runtime O(n) เหมือนกัน แต่ของ run เท่กว่าคับ

#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    Node *next;
    Node *prev;
} Node;

int main() {
    int L, N;
    cin >> L >> N;

    int sum = 0;
    int count = 1;
    unordered_map<int, Node *> link;

    for (int i = 0; i < L; i++) {
        int a;
        cin >> a;
        sum += a;
        Node *current = new Node;
        current->data = count;
        current->next = nullptr;
        current->prev = nullptr;
        link[count] = current;
        count++;
        while (count <= sum) {
            Node *newNode = new Node;
            newNode->data = count;
            newNode->next = nullptr;
            newNode->prev = current;
            current->next = newNode;
            current = newNode;
            count++;
        }

        link[sum] = current;
    }

    // for (auto x : link) {
    //     cout << x.first << ">";
    //     Node *current = x.second;
    //     while (current != nullptr) {
    //         cout << current->data << " ";
    //         current = current->next;
    //     }
    //     cout << "\n";
    // }

    Node *iter = link[1];
    Node *backward = link[1]->prev;
    Node *forward = link[1]->next;
    while (N--) {
        char command;
        cin >> command;

        // cout << N << " " << command << " " << iter->data << " " << forward
        //      << " " << backward << "\n";
        if (command == 'B') {
            if (backward == nullptr) {

            } else if (backward->next != iter) {
                forward = iter;
                iter = backward;
                backward = backward->next;
            } else {
                forward = iter;
                iter = backward;
                backward = backward->prev;
            }
        } else if (command == 'F') {
            if (forward == nullptr) {

            } else if (forward->next != iter) {
                backward = iter;
                iter = forward;
                forward = forward->next;
            } else {
                backward = iter;
                iter = forward;
                forward = forward->prev;
            }
        } else if (command == 'C') {

            int head;
            cin >> head;
            if (forward != nullptr) {
                link[forward->data] = forward;
                if (forward->next == iter) {
                    forward->next = nullptr;
                } else if (forward->prev == iter) {
                    forward->prev = nullptr;
                }
            }

            link.erase(iter->data);

            if (iter->prev == forward) {
                iter->prev = link[head];
            } else {
                iter->next = link[head];
            }

            if (link[head]->prev == nullptr) {
                link[head]->prev = iter;
            } else {
                link[head]->next = iter;
            }
            forward = link[head];

            if (forward == nullptr) {
                continue;
            } else if (forward->next != iter) {
                backward = iter;
                iter = forward;
                forward = forward->next;
            } else {
                backward = iter;
                iter = forward;
                forward = forward->prev;
            }
            // cout << command << " " << head << "\n";
            // Node *current = link[1];
            // Node *myforward = link[1]->next;

            // while (1) {
            //     cout << current->data << " ";
            //     if (myforward == nullptr) {
            //         break;
            //     } else if (myforward->next != current) {
            //         current = myforward;
            //         myforward = myforward->next;
            //     } else if (myforward->prev != current) {
            //         current = myforward;
            //         myforward = myforward->prev;
            //     }
            // }
            // cout << "\n";
        }
        cout << iter->data << " ";
    }
    // Node *current = link[1];
    // Node *myforward = link[1]->next;

    // while (1) {
    //     cout << current->data << " ";
    //     if (myforward == nullptr) {
    //         break;
    //     } else if (myforward->next != current) {
    //         current = myforward;
    //         myforward = myforward->next;
    //     } else if (myforward->prev != current) {
    //         current = myforward;
    //         myforward = myforward->prev;
    //     }
    // }

    return 0;
}