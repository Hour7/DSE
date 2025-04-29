#include <iostream>
using namespace std;

class Stack {
private:
    int arr[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    // isFull function
    bool isFull() {
        return (top >= 9);
    }

    // Push function
    bool push(int x) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    // Pop function
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // isEmpty function
    bool isEmpty() {
        return (top < 0);
    }

    // Peek function
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Size function
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Stack size after pop is: " << s.size() << endl;

    if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
