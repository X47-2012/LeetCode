#include <queue>
#include <iostream>
using namespace std;

queue<int> q1;
queue<int> q2;

bool empty() {
    return q1.empty() && q2.empty();
}

void push(int x) {
    if (!q1.empty()) {
        q1.push(x);
    } else {
        q2.push(x);
    }
}

    // Removes the element on top of the stack.
void pop() {
    if (empty()) {
        return;
    }

    if (!q1.empty()) {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    } else {
        while(q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
    }
}

    // Get the top element.
int top() {
    int x;
    if (!q1.empty()) {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        x = q1.front();
        q1.pop();
        q2.push(x);
    } else {
        while(q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        x = q2.front();
        q2.pop();
        q1.push(x);
    }

    return x;
}

int main() {

}
