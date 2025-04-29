#include <iostream>
using namespace std;

class Stack {
private:

    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top; 

public:

    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top; // Link the new node to the current top
        top = newNode; // Update the top to the new node
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top; // Store the current top
        top = top->next; // Move the top to the next node
        delete temp; // Free the memory of the old top
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack elements: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Stack elements after pop: ";
    s.display();

    return 0;
}