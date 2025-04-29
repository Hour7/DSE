#include <iostream>
using namespace std;

int arr[10];
int top = -1;

bool isFull() {
    return (top >= 9);
}

bool push(int x) {
    if (isFull()) {
        cout << "Stack overflow\n";
        return false;
    }
    arr[++top] = x;
    return true;
}

bool isEmpty() {
    return (top < 0);
}

int pop() {
    if (isEmpty()) {
        cout << "Stack underflow\n";
        return -1;
    }
    return arr[top--];
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

int size() {
    return top + 1;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

        cout << "Top element is: " << peek() << endl;
        cout << "Stack size is: " << size() << endl;

        cout << "Popped element is: " << pop() << endl;
        cout << "Stack size after pop is: " << size() << endl;

        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    return 0;
}
